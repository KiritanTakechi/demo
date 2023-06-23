#![cfg_attr(not(debug_assertions), windows_subsystem = "windows")]

use std::{process::{Command, Stdio}, io::Write};

fn main() {
    tauri::Builder::default()
        .invoke_handler(tauri::generate_handler![source, run])
        .run(tauri::generate_context!())
        .expect("error while running tauri application");
}

#[tauri::command]
fn source(x: &str) -> tauri::Result<String> {
    let filename = format!("./source/{}.cpp", x);
    let content = tauri::api::file::read_string(filename)?;
    Ok(content)
}

#[tauri::command]
fn run(x: &str, input: &str) -> tauri::Result<String> {
    let cpp_executable = if cfg!(target_os = "windows") {
        format!("./bin/{}.exe", x)
    } else {
        format!("./bin/{}", x)
    };

    // 执行 C++ 可执行文件并捕获输出
    let mut child = Command::new(cpp_executable)
        .stdin(Stdio::piped())
        .stdout(Stdio::piped())
        .stderr(Stdio::piped())
        .spawn()
        .expect("Failed to execute C++ executable");

    // 将输入内容写入子进程的标准输入
    if let Some(stdin) = child.stdin.as_mut() {
        stdin
            .write_all(input.as_bytes())
            .expect("Failed to write to stdin");
    }

    // 等待子进程执行完毕并获取输出
    let output = child
        .wait_with_output()
        .expect("Failed to wait for child process");

    // 将输出转换为字符串
    let output_str = String::from_utf8_lossy(&output.stdout);

    Ok(output_str.to_string())
}

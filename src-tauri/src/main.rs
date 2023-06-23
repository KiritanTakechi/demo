#![cfg_attr(not(debug_assertions), windows_subsystem = "windows")]

use std::{
    io::Write,
    process::{Command, Stdio},
};

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
        .spawn()?;

    // 将输入内容写入子进程的标准输入
    if let Some(stdin) = child.stdin.as_mut() {
        stdin.write_all(input.as_bytes())?;
    }

    // 等待子进程执行完毕并获取输出
    let output = child.wait_with_output()?;

    // 检查错误输出，如果存在则返回错误
    if !output.stderr.is_empty() {
        return Ok(String::from_utf8_lossy(&output.stderr).to_string());
    }

    // 将输出转换为字符串
    let output_str = String::from_utf8_lossy(&output.stdout);

    // 检查输出是否为空，如果为空则返回错误
    if output_str.is_empty() {
        return Ok("Command did not return any output".to_string());
    }

    Ok(output_str.to_string())
}

use std::{process::{Command, Stdio}, io::Write};



#[test]
fn run_test() {
    let x = "avl";
    let input = "5 88 70 61 96 120";

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

    println!("{output_str}");
}

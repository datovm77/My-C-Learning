#include <iostream>
#include <string>  // 核心
#include <format>  

using namespace std;

int main() {
    // 1. 创建与修改 (std::string)
    string filename = "report";
    
    // 2. 现代拼接 (append / +=)
    filename += "_2025"; 
    
    // 3. 现代格式化 (std::format) - 代替 sprintf
    int version = 5;
    // 结果: "File: report_2025_v5.txt"
    string final_name = format("File: {}_v{}.txt", filename, version);
    
    cout << final_name << endl;

    // 4. 现代查询 (starts_with, contains)
    // 语义清晰，不用去比对 != npos
    if (final_name.ends_with(".txt")) {
        cout << "这是一个文本文件" << endl;
    }
    
    if (final_name.contains("2025")) { // C++23 特性
        cout << "这是今年的文件" << endl;
    }

    // 5. 简单的数值转换
    string s_num = to_string(123.456);
    
    return 0;
}
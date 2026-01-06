#include <iostream>
#include <format> // C++20 新特性
#include <string>

using namespace std;

int main() {
    string name = "Alice";
    int score = 95;
    double gpa = 3.85234;

    // 1. 简单的拼接 (替代 %s %d)
    string s1 = format("Student: {}, Score: {}", name, score);
    cout << s1 << endl;

    // 2. 结构化打印 (替代 %-10s %5.2f)
    // {:<10} -> 左对齐，宽10
    // {:.2f} -> 浮点数保留2位
    cout << format("Name: {:<10} | GPA: {:.2f}", name, gpa) << endl;

    // 3. 补零 (常用于时间或编号)
    int id = 7;
    // {:0>3} -> 宽度3，右对齐(>)，空白处补0
    cout << format("ID: {:0>3}", id) << endl; // 输出 007

    return 0;
}
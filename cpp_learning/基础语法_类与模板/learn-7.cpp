#include <iostream>
using namespace std;

int main() {
    // 一个 int 占 4 个字节
    int big_number = 16909060; 
    // 16909060 的十六进制是 0x01020304
    // 内存里会存成 04 03 02 01 (小端序)

    // 字符数组
    char text[] = "ABCD";

    // int 数组
    int arr[] = {10, 20};

    cout << "Ready to debug memory..." << endl; // 打断点在这一行
    return 0;
}
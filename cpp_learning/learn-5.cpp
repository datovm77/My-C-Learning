#include <iostream>
using namespace std;
//学习debug
// 一个简单的函数：把输入的数字乘以 2
int doubleValue(int x) {
    int result = x * 2;
    return result; 
}

int main() {
    int total = 0;
    
    // 循环 5 次
    for (int i = 0; i < 5; i++) {
        int temp = doubleValue(i); // 调用函数
        total += temp;
        
        cout << "当前 i: " << i << ", temp: " << temp << ", total: " << total << endl;
    }

    cout << "最终结果: " << total << endl;
    return 0;
}
#include <iostream>
using namespace std;

int main() {
    // 我们的目标：计算这 5 个数的和
    // 预期结果：10 + 20 + 30 + 40 + 50 = 150
    int arr[] = {10, 20, 30, 40, 50}; 
    
    int total = 0;

    // !!! 注意：这里隐藏了一个 Bug
    // 数组长度是 5，下标应该是 0 到 4
    for (int i = 0; i <= 5; i++) {
        int current_num = arr[i];
        total += current_num;
        
        // 我们在这里假装打印一下，迷惑你
        cout << "第 " << i << " 次循环，加上了: " << current_num << endl;
    }

    cout << "-----------------------" << endl;
    cout << "最终总和: " << total << endl; 
    
    return 0;
}
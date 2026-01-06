#include <stdio.h>

int main() {
    int numbers[100];  // 存储输入的数字，最多100个
    int count = 0;     // 记录实际读取的数字个数
    int num;           // 临时变量，存储当前读取的数字
    
    // 循环读取输入，直到遇到0
    while (scanf("%d", &num) == 1 && num != 0) {
        numbers[count] = num;  // 将数字存入数组
        count++;               // 计数加1
    }
    
    // 倒序输出数字
    for (int i = count - 1; i >= 0; i--) {
        printf("%d", numbers[i]);  // 输出当前数字
        
        // 如果不是最后一个数字，输出一个空格
        if (i > 0) {
            printf(" ");
        }
    }
    
    return 0;
}
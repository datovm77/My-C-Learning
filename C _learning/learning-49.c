#include <stdio.h>

// 函数声明
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);

int main() {
    // 定义函数指针数组 - 包含4个函数指针
    int (*operations[4])(int, int) = {add, subtract, multiply, divide};
    
    int a = 10, b = 5;
    
    // 通过数组索引调用不同的函数
    for(int i = 0; i < 4; i++) {
        printf("操作%d的结果: %d\n", i+1, operations[i](a, b));
    }
    
    return 0;
}

// 函数定义
int add(int a, int b) { return a + b; }
int subtract(int a, int b) { return a - b; }
int multiply(int a, int b) { return a * b; }
int divide(int a, int b) { return a / b; }
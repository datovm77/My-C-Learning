#include <stdio.h>

// 几个示例函数
int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

void print_hello() {
    printf("Hello World!\n");
}

int main() {
    // 声明函数指针
    int (*math_operation)(int, int);  //返回类型 (*指针变量名)(参数类型列表);
    void (*greet)();
    
    // 指向不同函数
    math_operation = &add;
    int result = math_operation(5, 3);
    printf("5 + 3 = %d\n", result); 
    
    math_operation = &subtract;
    printf("5 - 3 = %d\n", math_operation(5, 3));
    
    math_operation = &multiply;
    printf("5 * 3 = %d\n", math_operation(5, 3));
    
    greet = &print_hello;
    greet();
    
    return 0;
}
#include <iostream>


// 1. 返回局部变量引用 (错误示例)
int& test01() {
    int a = 10; // 局部变量存放在栈区，函数运行完后变量会被释放
    return a;
}

// 2. 返回静态变量引用 (正确示例)
int& test02() {
    static int a = 20; // 静态变量存放在全局区，程序运行结束后由系统释放
    return a;
}

int main() {

    // 不能返回局部变量的引用
    // 这里会触发警告，甚至导致程序崩溃，因为 ref 指向的是已释放的内存
    int& ref = test01();
    std::cout << "ref = " << ref << std::endl; 
    std::cout << "ref = " << ref << std::endl; 

    // 如果函数做左值，那么必须返回引用
    int& ref2 = test02();
    std::cout << "ref2 = " << ref2 << std::endl;
    std::cout << "ref2 = " << ref2 << std::endl;

    // 函数调用作为左值进行赋值
    test02() = 1000; 

    std::cout << "ref2 = " << ref2 << std::endl;
    std::cout << "ref2 = " << ref2 << std::endl;


    return 0;
}
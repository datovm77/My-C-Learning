// 练习函数模板调用，知识点：显式指定模板参数与自动类型推导
#include <iostream>
#include <format>
#include <string>

template <typename T>
void swap(T &a, T &b)
{
    T temp = a;
    a = b;
    b = temp;
}

void test02()
{
    int a = 10;
    int b = 20;
    std::cout << "交换前" << std::endl;
    std::cout << std::format("a = {},b = {}", a, b) << std::endl;
    // swap(a,b);
    swap<int>(a, b);
    // swap<double>(a,b); 报错！
    std::cout << "交换后" << std::endl;
    std::cout << std::format("a = {},b = {}", a, b) << std::endl;
}

int main()
{
    test02();
    return 0;
}

// 练习引用、指针基础与宏定义，引用传参修改外部变量
#include<iostream>

#define LOG(x) std::cout << x << std::endl

void Increment(int& value)
{
    value++;
}

int main()
{
    int a = 5;
    int& ref = a;   //ref引用a
    int *b = &a;
    LOG(*b);
    // ref = 2;
    Increment(a);
    LOG(a);

}
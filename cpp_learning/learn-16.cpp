#include<iostream>
#include<format>

//new的基础语法
int *func()
{
    int *p = new int(10);
    return p;
}

//new创建数组
int *func2()
{
    int *p = new int[10];
    //delete[] p;
    return p;
}
int main()
{
    int *p = func();
    std::cout << *p << std::endl;
    std::cout << *p << std::endl;
    std::cout << *p << std::endl;

    delete p;

    //std::cout << *p << std::endl;

    return 0;
}
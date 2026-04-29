// 练习引用与函数重载中的const匹配问题
#include<iostream>

// void func(const int &a)
// {
//     std::cout<<"func(const int &a)调用"<< std::endl ;
// }

// void func(int &a)
// {
//     std::cout<<"func(int &a)调用"<< std::endl ;
// }

void func(int a)
{
    std::cout<<"func(int a)调用"<< std::endl ;
}
int main()
{
    const int a = 10;
    int b = 10;
    // func(a);
    func(10);
    // func(b);


    return 0;
}

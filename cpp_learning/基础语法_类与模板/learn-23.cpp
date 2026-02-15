#include<iostream>
#include<string>

//class:默认权限为私有
//struct:默认权限为公共

class C1
{
    int m_A;//默认私有
};

struct C2
{
    int m_A;//默认公共
};


int main()
{

    C1 c1;
    //c1.m_A = 100;
    //成员 "C1::m_A" (已声明 所在行数:9) 不可访问

    C2 c2;
    c2.m_A = 100; //正确地写法

    return 0;
}
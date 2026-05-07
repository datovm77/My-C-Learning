// 练习继承同名隐藏，知识点：同名成员与同名函数的访问
#include<iostream>
#include<string>
#include<format>
class Base
{
public:
    Base(): m_A(100) {}
    int m_A;
public:
    void func()
    {
        std::cout << std::format("Base下的func函数") << std::endl;
    }

};

class son:public Base
{
public:
    son():m_A(200){}
public:
    void func()
    {
        std::cout << std::format("son下的func函数") << std::endl;
    }
    int m_A;
};

void test01()
{
    son s;
    std::cout << std::format("son 下的m_A = {}",s.m_A) << std::endl;  //直接访问是子类的数据
    std::cout << std::format("Base 下的m_A = {}",s.Base::m_A) << std::endl;  //直接访问是子类的数据
}

void test02()
{
    son s;
    s.func(); //直接调用 是子类中的同名函数
    s.Base::func(); //加上作用域 
}

int main()
{
    //test01();

    test02();
    return 0;
}

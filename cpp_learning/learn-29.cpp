#include<iostream>

class Person
{
    public:
    //常函数
    Person(): m_A(0),m_b(0){}

    void showPerson() const
    {
        // m_A = 100;
        //this->m_A = 100;
        this->m_b = 100;  //mutable 声明过
    }
    void func()
    {

    }
    int m_A;
    mutable int m_b;//特殊变量，即使在常函数中也可以修改这个值
};

void test01()
{
    Person p1;
    p1.showPerson();
    std::cout << p1.m_b << std::endl;
}

void test02()
{
    const Person p2;
    //p2.m_A = 100;
    p2.m_b = 100;  //m_b为特殊值
    p2.showPerson();//可以调用
    //p2.func()无法调用
}

int main()
{
    test01();
    return 0;
}
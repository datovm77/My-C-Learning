// 练习函数模板的完全特化与const char*比较
#include<iostream>
#include<format>

template<typename T>
class MyClass {
public:
    MyClass(T val) : m_value(val) {}
private:
    T m_value;
};

void test01()
{
    MyClass p1(15);
}

int main()
{

    return 0;
}
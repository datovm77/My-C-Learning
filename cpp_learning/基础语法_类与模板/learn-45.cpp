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
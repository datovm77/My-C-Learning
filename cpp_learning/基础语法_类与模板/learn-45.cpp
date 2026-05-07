// 练习类模板基础，知识点：模板类定义与类模板参数推导
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

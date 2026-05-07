// 练习类模板友元函数，知识点：友元函数类内定义与访问私有成员
#include<iostream>
#include<format>
#include<string>

template<class T1,class T2>
class Person
{
public:
    Person (T1 age,T2 name): m_age(age),m_name(name) {}

    friend void show_info(const Person &p) 
    {
        std::cout << std::format("名字是：{}，年龄是：{}",p.m_name,p.m_age);
    }

private:
    T1 m_age;
    T2 m_name;
};

void test01()
{
    Person<std::string,int>p1("gem",25);
    show_info(p1);
}

int main()
{
    test01();

    return 0;
}

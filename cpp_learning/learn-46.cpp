#include<iostream>
#include<format>
#include<string>

template<class Typename,class Typeage>
class Person
{
public:
    Person(const Typename& name,const Typeage& age) : m_name(name),m_age(age) {}

    void show_info() const
    {
        std::cout << std::format("姓名是：{}，年龄是：{}",m_name,m_age) << std::endl;
    }

private:
    Typename m_name;
    Typeage m_age;
};

void way1(const Person<std::string,int> &p)
{
    std::cout << "第一种调用方式" << std::endl;
    p.show_info();
}

void test01()
{
    Person<std::string,int>p1("gem",34);



}

int main()
{

    return 0;
}
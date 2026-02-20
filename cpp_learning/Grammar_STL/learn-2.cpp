#include <iostream>
#include <format>
#include <string>
#include <vector>
#include <algorithm>
// vector algorithm

class Person
{
public:
    Person(const int &age, const std::string &name) : m_age(age), m_name(name) {}
    friend void test01();

private:
    int m_age;
    std::string m_name;
};

void test01()
{
    Person p1(13, "s");
    Person p2(15, "a");
    Person p3(14, "d");
    Person p4(17, "v");
    std::vector<Person> v = {p1, p2, p3, p4};

    std::cout << "-------第一种--------" << std::endl;
    for (std::vector<Person>::iterator it = v.begin(); it != v.end(); it++)
    {
        std::cout << std::format("姓名是：{}，年龄是{}", it->m_name, it->m_age) << std::endl;
    }
    std::cout << "-------第二种--------" << std::endl;
    for (auto it = v.begin(); it != v.end(); it++)
    {
        std::cout << std::format("姓名是：{}，年龄是{}", (*it).m_name, (*it).m_age) << std::endl;
    }
    std::cout << "-------第三种--------" << std::endl;
    for (const Person &p : v)
    {
        std::cout << std::format("姓名是：{}，年龄是{}", p.m_name, p.m_age) << std::endl;
    }
    std::cout << "-------第四种--------" << std::endl;
    std::for_each(v.begin(), v.end(), [](Person p)
    { std::cout << std::format("姓名是：{}，年龄是：{}", p.m_name, p.m_age) << std::endl; });
}

int main()
{
    test01();

    return 0;
}
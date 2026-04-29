// 练习函数模板显式指定类型与自动推导
#include <iostream>
#include <format>


template <class NameType, class AgeType>
class Person
{
public:
    Person(const NameType& name,const AgeType &age) : m_name(name), m_age(age) {}
 
    void show_info() const //它不修改任何成员变量
    {
        std::cout << std::format("姓名是：{}，年龄是：{}", m_name, m_age) << std::endl;
    }

    AgeType m_age;
    NameType m_name;
};

void test01()
{
    //Person<std::string, int> p1("gem", 34);
    Person p1(std::string("gem"), 34);
    p1.show_info();
}
int main()
{
    test01();

    return 0;
}
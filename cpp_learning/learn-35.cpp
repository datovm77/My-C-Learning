#include<iostream>
#include<string>
#include<format>

class Person
{
public:
    Person(std::string name,int age): name(name),m_age(age) {}

    bool operator==(const Person&p1) const
    {
        if(this->m_age==p1.m_age && this->name == p1.name)
        {
            return true;
        }
        return false;
    }

private:
    std::string name;
    int m_age;
} ;


void test01()
{
    Person p1("gem",33);
    Person p2("zhangsan",18);
    Person p3("zhangsan",18);
    if(p2==p3)
    {
        std::cout << std::format("p2与p3完全相等") << std::endl;
    }
    else{
        std::cout << std::format("p2与p3不相等") << std::endl;
    }

}

int main()
{

    test01();

    return 0;
}
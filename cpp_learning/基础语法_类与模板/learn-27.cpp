#include<iostream>
#include<format>

class Person
{
public:
    Person(int age)
    {
        this->age = age;
    }

    Person& Personadd_age(const Person&p)
    {
        this->age+=p.age;
        return *this;
    }

    int age;

};

void test01()
{
    Person p1(10);
    std::cout<<std::format("p1的年龄是{}",p1.age)<< std::endl;
}


void test02()
{
    Person p1(10);
    Person p2(10);

    //p2.Personadd_age(p1);
    p2.Personadd_age(p1).Personadd_age(p1).Personadd_age(p1).Personadd_age(p1);
    std::cout << std::format("p2调用后的年龄是{}",p2.age) << std::endl;
}


int main()
{
    //test01();
    test02();
    return 0;
}








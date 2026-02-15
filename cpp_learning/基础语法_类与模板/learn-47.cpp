#include<iostream>
#include<format>
#include<string>

template<class T1,class T2>
class Person
{
public:
    void show_info() const;

    Person(const T1& name,const T2 &age);

    
private:
    T1 m_name;
    T2 m_age;
};

template<class T1,class T2>
Person<T1,T2>::Person(const T1& name,const T2 &age) : m_name(name),m_age(age) {} 

template<class T1,class T2>
void Person<T1,T2>::show_info() const
{
    std::cout << std::format("姓名是：{}，年龄是：{}", m_name, m_age) << std::endl;
}

void test01()
{
    Person p1(std::string("dzq"),34);
    p1.show_info();
}

int main()
{
    test01();
    return 0;
}



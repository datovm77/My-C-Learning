#include<iostream>
#include<format>
struct person
{
private:
    int m_age ;

public:

    person() : m_age(0)
    {
        std::cout<< "person的无参构造"<<std::endl;
    }

    person(int a) : m_age(a)
    {
        std::cout<< "person的有参构造"<<std::endl;
    }

    person (const person &p) : m_age(p.m_age)
    {
        std::cout<< "person的拷贝构造"<<std::endl;
    }

    void setmy_age(int my_age)
    {
        this->m_age = my_age;
    }

    int knowm_age()
    {
        return m_age;
    }

    ~person()
    {
        std::cout<< "person的析构函数调用"<<std::endl;
    }

};
void test01()
{
    person p1;
    p1.setmy_age(10);

    person p2(p1);

    std::cout << std::format("p2的年龄为：{}岁",p2.knowm_age()) << std::endl;

}
int main()
{
    test01();
    return 0;
}
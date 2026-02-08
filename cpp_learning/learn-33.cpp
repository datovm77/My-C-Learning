#include<iostream>
#include<format>

class Person
{
    friend std::ostream& operator<<(std::ostream& os,const Person &p1);
public:
    Person():m_A(0){}

    Person& operator++()
    {
        m_A++;
        return *this; 
    }

    Person operator++(int)
    {
        Person temp = *this;
        m_A++;
        return temp;
    }


private:
    int m_A;
};

std::ostream& operator<<(std::ostream& os,const Person &p1)
{
    std::cout << p1.m_A ;
    return os;
}
void test01()
{
    Person p1;

    std::cout << ++(++p1) <<std::endl;

}

void test02()
{
    Person p2;
    std::cout << (p2++)++ << std::endl;
    std::cout << p2 << std::endl;
}

int main()
{
    //test01();
    test02();
    return 0;
}
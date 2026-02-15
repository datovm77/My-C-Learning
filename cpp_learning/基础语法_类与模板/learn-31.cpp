#include<iostream>
#include<string>
#include<format>
class Person
{
public:
    int m_A;
    int m_B;

    Person():m_A(0),m_B(0){}

    Person operator+(Person&p1)
    {
        Person temp;
        temp.m_A = p1.m_A + this->m_A;
        temp.m_B = p1.m_B + this->m_B;
        return temp;
    }


};

// Person operator+(Person&p1,Person&p2)
// {
//     Person temp;
//     temp.m_A = p1.m_A+p2.m_A;
//     temp.m_B = p1.m_B+p2.m_B;
//     return temp;
// }


void test01()
{
    Person p1;
    Person p2;
    p1.m_A = 11;
    p1.m_B = 12;
    p2.m_A = 13;
    p2.m_B = 14;

    Person p3;
    p3 = p1+p2;
    std::cout << std::format("p3的m_A的值为{}，m_B的值的{}",p3.m_A,p3.m_B) << std::endl;
}

int main()
{
    test01();


    return 0;
    
}
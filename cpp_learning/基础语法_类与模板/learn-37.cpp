#include <iostream>

class Base
{
public:
    int m_A;

protected:
    int m_B;

private:
    int m_C;

public:
    Base() : m_A(0), m_B(0), m_C(0) {}
};

class son1 : public Base
{
public:
    son1()
    {
        m_A = 100; // 可以访问，因为 m_A 是 public
        m_B = 100; // 可以访问，因为 m_B 是 protected（子类可访问）
        // m_C = 100;  // 错误！m_C 是 private，子类不可访问
    }
};

class son2 : protected Base
{
public:
    son2()
    {
        m_A = 100; // 可以访问，因为 m_A 是 public
        m_B = 100; // 可以访问，因为 m_B 是 protected（子类可访问）
        // m_C = 100;  // 错误！m_C 是 private，子类不可访问
    }
};

void test01()
{
    son1 s1;
    //s1.m_B = 100;不可访问

    son2 s2;
    //s2.m_A = 100; 是protected类型不可以访问

}

int main()
{
    test01();
    return 0;
}
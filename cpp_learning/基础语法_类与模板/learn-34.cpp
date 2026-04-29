// 练习深拷贝构造与赋值运算符重载，防止指针悬空
#include <iostream>
#include <format>

class Person
{
    friend void test01();

public:
    Person(int a) : m_age(new int(a)) {}

    // 拷贝构造函数（深拷贝）
    Person(const Person &p) : m_age(new int(*p.m_age)) {}

    Person &operator=(const Person &p)
    {
        if (m_age != NULL) // 表示这个指针指向不为空
        {
            delete m_age;
            m_age = NULL;
        }

        m_age = new int(*p.m_age);

        return *this;
    }

    ~Person()
    {
        if (m_age != NULL)
        {
            delete m_age;
            m_age = NULL;
        }
    }

private:
    int *m_age;
};

void test01()
{
    Person p1(10);
    Person p2(11);
    Person p3(12);
    std::cout << std::format("p1的年龄是{}，p2的年龄是{}，p3的年龄是{}", *p1.m_age, *p2.m_age, *p3.m_age) << std::endl;

    p1 = p2 = p3;

    std::cout << std::format("p1的年龄是{}，p2的年龄是{}，p3的年龄是{}", *p1.m_age, *p2.m_age, *p3.m_age) << std::endl;

}

int main()
{

    test01();
    return 0;
}
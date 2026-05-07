// 练习构造与析构基础，知识点：无参、有参、拷贝构造与动态成员
#include<iostream>
#include<format>
struct person
{
public:
    int m_age ;
    int *m_height;
public:

    person()
    {
        std::cout<< "person的无参构造"<<std::endl;
    }

    person(int a,int height) : m_age(a),m_height(new int(height))
    {
        std::cout<< "person的有参构造"<<std::endl;
    }

    person (const person &p) : m_age(p.m_age)
    {
        std::cout<< "person的拷贝构造"<<std::endl;
    }


    ~person()
    {
        std::cout<< "person的析构函数调用"<<std::endl;
    }

};
void test01()
{


}
int main()
{
    test01();
    return 0;
}

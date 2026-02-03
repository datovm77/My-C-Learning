#include<iostream>
#include<format>
#include<string>
//类与对象
//三大特性:封装，继承，多态
//封装：把属性与行为作为一个整体

class Student
{
    //访问权限
    //公共权限
public:
    //属性
    std::string m_name;
    int m_id;
    //行为:显示姓名与学号
    void showStudent()
    {
        std::cout << std::format("姓名是：{}，学号是：{}",m_name,m_id) << std::endl;
    }
    
};

int main()
{

    Student s1;
    s1.m_name = "zhangsan";
    s1.m_id = 114545;

    s1.showStudent();

    Student s2;
    s2.m_name = "lisi";
    s2.m_id = 13565;

    s2.showStudent();
    return 0;
}
#include<iostream>
#include<string>
#include<format>
//类与对象
//三大特性:封装，继承，多态
//封装：把属性与行为作为一个整体


//访问权限
//公共权限 public       成员类内，类外都可以访问
//保护权限 protected    成员类内可以访问，类外不可以访问 子可以访问保护内容
//私有权限 private      成员类内可以访问，类外不可以访问 子不可以访问保护内容

class Person
{
public:
    //公共权限
    std::string m_name;
protected:
    //保护权限
    std::string m_car;
private:
    //私有权限
    int m_Password;


public:
    //公共权限
    void func()
    {
        m_name = "zhangsan";
        m_car = "tesla";
        m_Password = 123456;
    }    

};

int main()
{
    Person p1;
    //p1.m_car = "宝马";
    //成员 "Person::m_car" (已声明 所在行数:21) 不可访问


    return 0;
}
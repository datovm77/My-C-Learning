// 练习结构体定义与访问，知识点：struct初始化与指针访问成员
#include<iostream>
#include<format>

struct Student
{
    std::string name;
    int age;
    int score;
};

int main(void)
{
    Student s1 = {"张三",24,100};
    Student *p = &s1;

    std::cout<< "姓名是："<< p->name  << ",年龄是："<< p->age << ",分数是:" << p->score << std::endl ;
    std::cout<< std::format("姓名是:{}，年龄是:{}，成绩是:{} ", p->name,p->age,p->score) << std::endl ;

    return 0;
}

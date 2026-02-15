#include<iostream>
#include<format>

struct Student
{
    int age;
    int score;
    std::string name;
};

//内容传递
void printStudent1(Student s)
{
    std::cout << std::format("学生的姓名：{}，年龄是：{}，成绩是：{}",s.name,s.age,s.score) << std::endl ; 
}


//地址传递
void printStudent2(const Student *p)
{
    //p->name = "llll"   使用const可以防止被修改
    std::cout << std::format("学生的姓名：{}，年龄是：{}，成绩是：{}",p->name,p->age,p->score) << std::endl ; 
}

int main()
{
    Student s1 = {23,99,"电子琴"};
    printStudent1(s1);
    printStudent2(&s1);
    return 0;
}
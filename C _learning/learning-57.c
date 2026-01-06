#include <stdio.h>

struct Student
{
    char name[100];
    int age;
};
int main()
{
    struct Student stu1 = {"zhangsan", 13};
    struct Student stu2 = {"lisi", 23};
    struct Student stu3 = {"wangwu", 66};

    struct Student stuArr[3] = {stu1, stu2, stu3};

    // 遍历数组
    for (int i = 0; i < 3; i++)
    {
        struct Student temp = stuArr[i];
        printf("学生的姓名为%s，年龄为：%d \n", temp.name, temp.age);
    }

    // ctrl + k 与ctrl + f可以格式化
    return 0;
}
#include<stdio.h>
#include<string.h>

typedef struct 
{
    char name[100]; //是一个字符数组，不是指针，但它可以像指针一样使用（因为数组名在表达式中会退化为指针）
    int age;
} S ;

void method(S* p);

int main()
{
    
    //进行赋值初值
    S stu = {"gem",18};
    printf("学生的初始数据为:%s,%d \n",stu.name,stu.age);

    //调用函数
    method(&stu);

    printf("学生的修改后的数据为:%s,%d \n",stu.name,stu.age);

    return 0;
}

void method(S* p)
{
    printf("接收到main函数中的初始数据为:%s,%d\n",(*p).name,(*p).age);

    printf("输入要修改学生的名字");
    scanf("%s",(*p).name);  
    printf("输入要修改学生的年龄");
    scanf("%d",&((*p).age));

    printf("函数中修改后数据为:%s,%d\n",(*p).name,(*p).age);
}
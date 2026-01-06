#include<stdio.h>
#include<string.h>

struct Message
{
    char phone[12];
    char mail[100];
};

struct Student
{
    char name[100];
    int age;
    char gender;
    double height;
    struct Message msg;
    
};

int main()
{
    //定义学生类型的变量
    struct Student stu;

    //对里面的每一个变量进行赋值
    strcpy(stu.name,"zhangsan");
    stu.age = 23;
    stu.gender = 'M';
    stu.height = 1.78;
    
    strcpy(stu.msg.phone,"13534454");
    strcpy(stu.msg.mail,"13534454@qq.com");

    printf("学生的信息为： \n");
    printf("姓名为: %s\n",stu.name);
    printf("年龄为:%d\n",stu.age);
    printf("性别为:%c\n",stu.gender);
    printf("身高为:%lf\n",stu.height);

    printf("手机号为:%s\n",stu.msg.phone);
    printf("邮箱为:%s\n",stu.msg.mail);

    printf("-------------------------------\n");

    //一次性赋值

    struct Student stu2 = {"gem",34,'W',1.64,{"134154355","4354341@qq.com"}};

    printf("学生的信息为： \n");
    printf("姓名为: %s\n",stu2.name);
    printf("年龄为:%d\n",stu2.age);
    printf("性别为:%c\n",stu2.gender);
    printf("身高为:%lf\n",stu2.height);

    printf("手机号为:%s\n",stu2.msg.phone);
    printf("邮箱为:%s\n",stu2.msg.mail);


    

    return 0;
}


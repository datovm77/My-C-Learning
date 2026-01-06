//结构体:自定义的数据类型，一批数据组合的结构型数据
#include<stdio.h>
#include<string.h>
/*
    书写位置：
    函数里面：局部位置，只可以在本函数使用
    函数外面:全局位置，所有函数都可以用


*/
struct GirlFriend
{
    char name[100];
    int age;
    char gender;
    double height;
};

int main()
{
    struct GirlFriend gf1;
    strcpy(gf1.name,"GEM");
    gf1.age = 34;
    gf1.gender = 'e';
    gf1.height = 1.66;

    //打印
    printf("邓紫棋的名字为:%s \n",gf1.name);    
    printf("邓紫棋的身高为:%f \n",gf1.height);    
    printf("邓紫棋的性格为:%c \n",gf1.gender);    
    printf("邓紫棋的年龄 为:%d \n",gf1.age);    
       

    return 0;
}
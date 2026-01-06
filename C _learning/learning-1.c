#include<stdio.h>
int main()
{
    char name[20];
    int age;
    float height;
    printf("请输入你的名字，年龄，身高:");
    scanf("%s %d %f",&name,&age,&height);
    printf("我知道了！！你的身高是：%.2f米,年龄是：%d岁！，名字是：%s",height,age,name);
    return 0;
}


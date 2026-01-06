//函数指针
#include<stdio.h>

void method1();
int method2(int num1,int num2);

int main()
{
    //定义函数指针
    void(*p1)() = method1;
    int (*p2)(int,int) = method2;

    //利用函数指针调用
    (*p1)();
    int num = (*p2)(10,20);
    printf("%d\n",num);


    return 0; 
}

void method1()
{
    printf("已经调用method1 \n");
}

int method2(int num1,int num2)
{
    printf("已经调用method2 \n");
    return num1+num2;
}
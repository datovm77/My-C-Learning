#include<stdio.h>
int add(int a, int b);
int subtract(int a, int b);
int multiply(int a, int b);
int divide(int a, int b);
int main()
{
    int num1;
    int num2;

    printf("输入两个整数: \n");
    scanf("%d%d",&num1,&num2);

    int(*p[4])(int,int) = {&add,&subtract,&multiply,&divide};//定义函数指针数组，可以：int(*p[4])(int,int) = {&add,&subtract,&multiply,&divide};

    printf("输入一个整数选择计算方式: \n");

    int num3;
    scanf("%d",&num3);
    int result = (p[num3 - 1])(num1, num2);  //p代表数组（函数指针数组）
    printf("%d\n", result);               
    //1.加法 2.减法 3.乘法 4.除法
    return 0;
}

int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;
}

int multiply(int a, int b) {
    return a * b;
}

int divide(int a, int b) {
    if (b == 0) {
        printf("错误：除数不能为零！\n");
        return 0;
    }
    return a / b;
}
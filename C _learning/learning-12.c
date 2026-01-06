#include<stdio.h>
int main()
{
    // +=
    //把左边和右边进行相加，结果赋值给左边，对右边没有影响
    int a = 10;
    int b = 20;
    a += b;  //a = a + b;
    printf("%d \n",a); //30
    printf("%d \n",b); //20

    // a *= b;  a = a *b;
    // a /= b;  a = a / b;
    // a%= b; a = a % b; 

    return 0;
}
#include<stdio.h>
int main()
{
    //整数反转
    int num = 12345678;
    int rev = 0;
    while(num !=0)
    {
        int temp = num % 10;   //123变成3赋值给temp
        rev = rev * 10 + temp;
        num = num / 10;

    }
    printf("倒过来为：%d \n",rev);
   
    return 0;
}
    /*
    1234进入
    int temp = num % 10;     temp为4
    rev = rev * 10 + temp;   rev为4
    num = num / 10;          num为123

    int temp = num % 10;     temp为3
    rev = rev * 10 + temp;   rev为43    40+3
    num = num / 10;          num为12

    int temp = num % 10;     temp为2
    rev = rev * 10 + temp;   rev为432
    num = num / 10;          num为1

    int temp = num % 10;     temp为1
    rev = rev * 10 + temp;   rev为4321
    num = num / 10;          num为0然后退出循环

    
    */


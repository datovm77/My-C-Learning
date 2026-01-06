#include<stdio.h>
int main()
{
    printf("输入一个数字： \n"); //判断是不是2的幂次方
    int a;
    scanf("%d",&a);
    while(a > 1 && a % 2 == 0)
    {
        a = a / 2;
    }

    if (a==1)
    {
        printf("yes  \n");
    }
    else
    {
        printf("no \n");
    }
   
    
    return 0;
}
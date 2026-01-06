#include<stdio.h>
int main()
{
    //整数反转
    int num = 123456789;
    printf("输入一个数字: \n");
    scanf("%d",&num);

    do
    {  
        printf("%d",num % 10 );
        num = num / 10;
    }
    while(num != 0);



    return 0;
}

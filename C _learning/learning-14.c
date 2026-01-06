#include<stdio.h>
int main()
{
    int a;
    printf("输入你的氪金总额： \n");
    scanf("%d",&a);
    if(a>=1&&a<100)
    {
        printf("尊贵的vip1 \n");
    }
    else if(a>=100&&a<499)
    {
        printf("尊贵的vip2 \n");
    }
    else if(a>=500&&a<999)
    {
        printf("尊贵的vip3 \n");
    }
    else if(a>=1000&&a<1999)
    {
        printf("尊贵的vip4 \n");
    }
    else if(a>=2000&&a<5000)
    {
        printf("尊贵的vip5 \n");
    }
    else if(a>=5000)
    {
        printf("大佬！！ \n");
    }
    else
    {
        printf("快去充值！ \n");
    }

    return 0;
}
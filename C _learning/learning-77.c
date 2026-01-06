#include<stdio.h>
//洛谷
int main()
{
    int m,t,s;
    scanf("%d %d %d",&m,&t,&s);
    if(t==0) //吃苹果的速度无限快
    {
        printf("0");
    }
    else if(m*t >= s)
    {
        
        if((s%t) == 0)
        {
            int eat = s / t;
            int rest = m - eat;
            printf("%d",rest);
        }
        else //刚好吃完一个苹果再过一点点时间
        {
            int eat = (s / t) + 1;   
            int rest = m - eat;
            printf("%d",rest);
        }
    }
    else{
        printf("0");  //吃完最后一个苹果了
    }

    return 0;
}
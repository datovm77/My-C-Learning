#include<stdio.h>
int main()
{
    int m,n;
    int ge;
    int shi;
    int bai;
    while((scanf("%d %d",&m,&n) == 2))
    {
        int flag = 0;
        for(int i = m;i<=n;i++)
        {
            ge = i % 10;
            shi = i / 10 % 10;
            bai = i / 100 % 10;
            if(i==ge*ge*ge+shi*shi*shi+bai*bai*bai)
            {
                if(flag==0)
                {
                    printf("%d",i);
                }
                else{
                    printf(" %d",i);
                }
                flag = 1;
            }
        }
        
        if(flag==0)
        {
            printf("no\n");
        }
        else
        {
            printf("\n");
        }
    }


    return 0;
}
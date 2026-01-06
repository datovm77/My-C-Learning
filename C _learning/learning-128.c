#include<stdio.h>
int main()
{
    int n,m; //n代表总长度    m代表一组的长度
    while((scanf("%d %d",&n,&m)) == 2)
    {
        int first = 0;
        int sum = 0;
        int count = 0;
        for(int i = 1;i <= n;i++)
        {
            sum += i*2;
            count++;
            if( count == m || i == n)
            {
                if(first)
                {
                    printf(" ");
                }
                printf("%d",sum/count);
                sum = 0;
                count = 0;
                first = 1;
            }
        }
        
        printf("\n");
    }

    return 0;
}
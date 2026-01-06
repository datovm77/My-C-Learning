#include<stdio.h>
int main()
{
    int n;
    int count[10] = {0};
    if(scanf("%d",&n)!=1) return 0;

    for(int i = 0;i < n;i++)
    {
        int num;
        scanf("%d",&num);

        if(num==0)
        {
            count[0]++;
        }

        while(num>0)
        {
            int digit = num % 10;
            count[digit]++;
            num/=10;
        }

    }
    int max_count = 0;
    for(int i = 0;i<10;i++)
    {
        if(count[i]>max_count) max_count = count[i];
    }
    printf("%d:",max_count);
    for(int i = 0;i<10;i++)
    {
        if(count[i]==max_count) printf(" %d",i);
    }
    printf("\n");
    return 0;
}
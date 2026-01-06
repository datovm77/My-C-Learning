#include<stdio.h>
int find(int n);
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 100;i<=n;i++)
    {
        if(find(i)==0)
        {
            printf("%d ",i);
        }
    }
    return 0;
}

int find(int n)
{
    int sum_result = 0;
    int temp = n;
    while(temp != 0)
    {
        int num = temp % 10;
        sum_result = sum_result + num*num*num;
        temp = temp / 10;
    }
    if(sum_result == n)
    {
        return 0;
    }
    else{
        return -1;
    }
}
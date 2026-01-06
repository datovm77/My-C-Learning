#include<stdio.h>
int is_zhinum(int n,int m);

int cal_result(int number)
{
    int count = 0;

    for(int i = 1;i<=number;i++)
    {
        if(is_zhinum(number,i) ==1 )
        {
            count++;
        }
    }
    return count;
}
int is_zhinum(int n,int m)  //n > m
{
    int result = n % m;
    if(result == 0)
    {
        return m;
    }
    return (is_zhinum(m,result));
}

int main()
{
    int T;
    scanf("%d",&T);
    for(int i = 0;i<T;i++)
    {
        int number;
        scanf("%d",&number);
        printf("%d\n",cal_result(number));
    }


    return 0;
}


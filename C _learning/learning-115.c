#include<stdio.h>
//回文数
int check(int num)
{
    int reverse_num = 0, temp = num;
    while(temp > 0) 
    {
    reverse_num = reverse_num * 10 + temp % 10;
    temp /= 10;
    }
return (reverse_num == num);
}
int main()
{
    //printf("%d\n",check(151)) ;
    int n,m;
    scanf("%d %d",&n,&m);
    for(n;n<=m;n++)
    {
        if(check(n))
        {
            printf("%d\n",n);
        }
    }
    return 0;
}
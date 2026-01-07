#include<stdio.h>
long long int GCD(long long int n,long long int m)  //编写最大公约数GCD函数
{
    long long temp;  //n>m
    while(m!=0)
    {
        temp = m;
        m = n % m;
        n = temp;
    }
    return n;

}
//两个数的最大公约数，等于其中较小的数和两数相除余数的最大公约数
long long int LCM(long long int n, long long int m) // 编写最小公倍数LCM函数
{
    return (n / GCD(n, m)) * m; // 最小公倍数*最大公约数 = a*b
}
int main()
{
    int n;
    while((scanf("%d",&n)) != EOF)
    {
        
        long long current_lcm;
        long long val;
        if(n>0)
        {
            scanf("%lld",&current_lcm);
        }
        for(int i = 0;i<n;i++)
        {
            scanf("%lld",&val);
            if(i>0)
            {
                long long int result1 = LCM(current_lcm,val);
                current_lcm = result1;
            }
        }
        printf("%lld\n",current_lcm);
    }


    return 0;
}


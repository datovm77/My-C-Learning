#include<stdio.h>

long long int GCD(long long int n,long long int m)
{
    long long temp;
    while(m!=0)
    {
        temp = m;
        m = n % m;
        n = temp;
    }
    return n;
}

long long int LCM(long long int n, long long int m)
{
    // 考点：防止 n*m 溢出，必须先除后乘
    // 注意：GCD可能返回0导致除0错误吗？
    // 在本题正整数背景下不会，但严谨起见，题目一般保证输入正整数。
    if (n == 0 || m == 0) return 0; 
    return (n / GCD(n, m)) * m;
}

int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        long long current_lcm;
        long long val;
        
        // 先读取第一个数作为初始的 LCM
        scanf("%lld", &current_lcm);
        
        // 既然已经读了1个，后面只需要再读 n-1 个
        for(int i = 1; i < n; i++) 
        {
            scanf("%lld", &val);
            // 累积计算：用当前的 LCM 和 新读入的数 计算新的 LCM
            current_lcm = LCM(current_lcm, val);
        }
        
        printf("%lld\n", current_lcm);
    }
    return 0;
}
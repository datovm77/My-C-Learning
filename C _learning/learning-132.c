#include<stdio.h>
int main()
{
    int n;
    long long f[56] ;
    f[1] = 1;f[2] = 2;f[3] = 3;f[4] = 4;
    
    //f[5] = f[4]+f[2];
    for(int i = 5;i<56;i++)
    {
        f[i] = f[i-1]+f[i-3];
    }
    while((scanf("%d",&n))==1 && n!=0)
    {
        printf("%lld\n",f[n]);
    }
    return 0;
}


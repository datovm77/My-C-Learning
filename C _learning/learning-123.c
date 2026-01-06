#include<stdio.h>

/*********Begin*********/
long long int GCD(long long int n,long long int m)  //编写最大公约数GCD函数
{
    long long int result = n % m;  //n>m
    if(result == 0)
    {
        return m;
    }
    return GCD(m,result);

}
//两个数的最大公约数，等于其中较小的数和两数相除余数的最大公约数


/*********Begin*********/
long long int LCM(long long int n,long long int m)  //编写最小公倍数LCM函数
{
    return ((n*m) / GCD(n,m));    //最小公倍数*最大公约数 = a*b
}

/*********End**********/ 
int main(void)
{  
    /*********Begin*********/
    //printf("%d\n",GCD(24,18));
    /*********End**********/ 
    long long int n,m;
    scanf("%Ld %Ld",&n,&m);
    if(n<0||m<0)
    {
        printf("Input Error\n");
        return 0;
    }
    printf("%Ld %Ld\n",GCD(n,m),LCM(n,m));
    return 0;
}

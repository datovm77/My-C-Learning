#include<stdio.h>
int main()
{
    int i,n;
    int fib[46];
    fib[0] = fib[1] = 1;  //初始化，生成斐波那契数列前两位
    printf("请输入数字n: \n");
    scanf("%d",&n);
    if(n>=1 && n<=46)
    {
        for(i=2;i<n;i++)
        {
        fib[i] = fib [i-1] + fib [i-2];   //这里可以把斐波那契数列放入数组
        }
        for( i = 0; i < n; i++ )
        {
            printf("%8d",fib[i]);
            if((i+1)%5==0) //每一行就输出5个数
            {
               printf("\n");
            }

        }
        if(n % 5 != 0)  //如果总数不是5的倍数，那就换行
        {
           printf("\n");
        }
        
    }
    else
        {
            printf("错误！！\n");       
        }


    return 0 ;
}
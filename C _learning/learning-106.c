#include<stdio.h>
#include<math.h>

int is_prime(int num); 

int main()
{
    int n;
    scanf("%d",&n);

    for(int i = 0; i < n; i++)
    {
        int number;
        scanf("%d", &number);
        
        for(int j = 2; j <= number / 2; j++)
        {
            if(is_prime(j) == 1) 
            {
                int num_rest = number - j;
                // 再判断：剩下的那个数也是素数
                if(is_prime(num_rest) == 1)
                {
                    printf("%d = %d + %d\n", number, j, num_rest);
                    break; // 找到第一个就停止
                }
            }
        }
    }
    return 0;
}

int is_prime(int num)
{
    // 特殊判断：防止 1 被误判，防止 2 被误判
    if(num <= 1) return 0; // 1不是素数
    if(num == 2) return 1; // 2是素数，直接返回1
    
    int temp = sqrt(num);
    
    // 循环从 2 到 sqrt(num)
    for(int j = 2; j <= temp; j++)
    {
        if( (num % j) == 0)
        {
            return 0; 
        }
    }
    return 1; // 循环走完都没发现因子，说明是素数，返回1
}
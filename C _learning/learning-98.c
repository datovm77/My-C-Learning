#include<stdio.h>
int is_prime(int num);

int main()
{
    int M, N;
    scanf("%d %d", &M, &N);
    
    long int sum = 0;
    int count = 0;
    
    for(int j = M; j <= N; j++)
    {
        if(is_prime(j))
        {
            count++;
            sum += j;
        }
    }
    
    printf("%d %ld\n", count, sum);
    return 0;
}

int is_prime(int num)
{
    if (num <= 1) return 0;
    
    if (num == 2) return 1;
    
    if (num % 2 == 0) return 0;
    
    for(int i = 3; i * i <= num; i += 2)
    {
        if(num % i == 0)
        {
            return 0; // 只要找到一个因数，就不是素数
        }
    }
    
    return 1; // 素数
}
#include<stdio.h>
#include<math.h>
int main()
{
    long long int N,R;
    while(scanf("%lld %lld",&N,&R)!=EOF)
    {
        if(N<0)
        {
            printf("-");
            N = -N;
        }
        if(N==0)
        {
            printf("0\n");
            continue;
        }
        char buffer[50];
        int index = 0;
        while(N>0)
        {
            int remainder = N % R;
            if(remainder < 10) buffer[index++] = remainder + '0'; 
            else buffer[index++] = remainder - 10 + 'A';
            N /= R;
        }
        for(int i = index-1;i>=0;i--)
        {
            printf("%c",buffer[i]);
        }
        printf("\n");
    }
    return 0;
}
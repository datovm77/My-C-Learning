#include<stdio.h>
int main()
{
   int n;
   scanf("%d",&n);
   int sum = 150;
   int five_coin = 5;
   int two_coin = 2;
   int one_coin = 1;
   int count = 0;
   for(int i = 1;i<=30;i++)
   {
    for(int j = 0;j <=75;j++)
    {
        int rest = sum - 5*i - 2*j;
        int number = rest + j + i;
        if(number == 100)
        {
            printf("%d %d %d\n",i,j,rest);
            count++;
            if(count == n)
            {
                return 0;
            }
        }
    }
     
   }
   return 0;
}
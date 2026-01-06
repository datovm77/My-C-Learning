#include<stdio.h>
int main()
{
   int i = 10;
   int j = 5;
   int k = i++ + ++i - --j - i--;
   printf("%d \n",k);
   return 0;
}
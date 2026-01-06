#include<stdio.h>

int main()
{
    int year;
    int mouth;
    int days;
    while(scanf("%d/%d/%d",&year,&mouth,&days)==3)
    {
        int deter = 0;
        if((year%4==0 && year%100!=0)||(year%400==0))
        {
            deter = 1;
        }
        if(mouth<=2 && days<=29)
        {
            deter = 0;
        }
        int arr[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
        int sum = 0;
        for(int i = 0;i<mouth-1;i++)
        {
            sum+=arr[i];
        }
        sum+=days;
        if(deter==1)
        {
            sum++;
        }
        printf("%d\n",sum);
    }
    

    return 0;
}
#include<stdio.h>
int main()
{
    int k; //与Sn比较的数
    scanf("%d",&k);
    int n; //代表Sn的项数，找出最小的Sn大于k
    double sum = 0;  //Sn
    int i = 1;
    while(sum <= k)
    {
        double An = 1.0 / (double)i ;
        sum = sum + An;
        i++;
    }

    printf("%d",i-1);

    return 0;
}
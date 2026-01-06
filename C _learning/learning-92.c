#include<stdio.h>
int main()
{
    double distant;
    scanf("%lf",&distant);
    double ability = 2.0;
    double sum = 0;
    int count = 0;
    while(sum < distant)
    {
        sum = sum + ability;
        ability = 0.98*ability;
        count++;
    }
    printf("%d\n",count);

    return 0;
}
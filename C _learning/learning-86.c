#include<stdio.h>
int main()
{
    double cal (int n);
    int n;
    scanf("%d",&n); 
    double sum = 0;
    double itmp;
    for(int i = 0; i < n ;i++)
    {
        itmp = 1.0 / cal(i+1);
        sum = sum + itmp;
    }
    double real_sum = sum + 1.0;
    printf("%.8lf",real_sum);

   return 0;
}

double cal (int n)
{
    double sum = 1;
    for(int i = 0;i < n;i++)
    {
        sum = sum*(i+1);
    }
    return sum;
}
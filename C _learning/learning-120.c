#include <stdio.h>
#include <math.h>
int jiechen(int num);
int main()
{
    double eps, x;
    if (scanf("%lf %lf", &eps, &x) != 2) return 0;

    double term  = 1;      // 第1项 = 1
    double sum = 0.0;
    int k = 1;

    // 递推关系：term_{k+1} = term_k * ( -x^2 / ((2k+1)*(2k+2)) )
    while (fabs(term) > eps) {
        term = pow(-1.0,k+1)*pow(x,(k-1)*2) / jiechen((k-1)*2);
        sum += term;
        k++;
    }

    printf("cos(%.2lf) = %.6lf", x, sum);
    return 0;
}

int jiechen(int num)
{
    int result = 1;
    int temp = num;
    if(temp == 0 )
    {
        return 1;
    }
    while(temp > 0)
    {
        result *= temp;
        temp--;
    }
    //printf("%d",result);
    return result;
}
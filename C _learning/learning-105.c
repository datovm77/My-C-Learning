#include <stdio.h>

int main() {
    double sum;
    scanf("%lf",&sum);
    double temp = sum;
    int count = 0;

    while(temp >= 4.0)
    {
        temp = temp / 2.0 - 2.0;
        count++;
    }
    printf("%d %.3lf",count,temp);
    return 0;
}
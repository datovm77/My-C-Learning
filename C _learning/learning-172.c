#include <stdio.h>
#include <math.h>
#include <string.h>
int cal_result(int n1, int n2)
{
    unsigned long long result;
    result = 1;
    while (n2--)
    {
        result *= n1;
        result = result % 1000;
    }

    return result;
}

int main()
{
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        if (n == 0 && m == 0)
            break;
        printf("%d\n", cal_result(n, m));
    }

    return 0;
}

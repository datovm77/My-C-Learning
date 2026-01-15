#include <stdio.h>
#include <math.h>
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int main()
{
    int n;
    while (scanf("%d", &n) == 1)
    {
        if (n == 0)
        {
            break;
        }
        int arr[105];
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
        }
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (abs(arr[j + 1]) > abs(arr[j]))
                {
                    swap(&arr[j + 1], &arr[j]);
                }
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (i > 0)
            {
                printf(" ");
            }
            printf("%d", arr[i]);
        }
        printf("\n");
    }

    return 0;
}

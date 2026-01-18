#include <stdio.h>
int main()
{
    int n;
    while ((scanf("%d", &n)) != EOF)
    {
        int arr[105][105];
        int top = 0;
        int left = 0;
        int bottom = n - 1;
        int right = n - 1;
        int num = 1;
        while (num <= n * n)
        {
            for (int i = left; i <= right; i++)
                arr[top][i] = num++;
            top++;

            for (int i = top; i <= bottom; i++)
                arr[i][right] = num++;
            right--;

            for (int i = right; i >= left; i--)
                arr[bottom][i] = num++;
            bottom--;

            for (int i = bottom; i >= top; i--)
                arr[i][left] = num++;
            left++;

            
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j > 0)
                    printf(" ");
                printf("%3d", arr[i][j]);
            }
            printf("\n");
        }
    }

    return 0;
}
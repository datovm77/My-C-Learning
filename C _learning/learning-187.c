#include <stdio.h>

int main()
{
    int n;
    if (scanf("%d", &n) == EOF) return 0;

    int arr[100][100];

    // 1. 输入矩阵
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    // 2. 按斜线层数 sum 遍历 (从 0 到 2n-2)
    for (int sum = 0; sum <= 2 * n - 2; sum++)
    {
        // === 情况 A：偶数层，往右上走 ===
        if (sum % 2 == 0)
        {
            int i, j;
            
            // 起点：左边界或底边界
            if (sum < n)
            {
                i = sum;      // 在左边界
                j = 0;
            }
            else
            {
                i = n - 1;    // 在底边界
                j = sum - (n - 1);
            }

            // 开始往右上走：行减小，列增加
            while (i >= 0 && j < n)
            {
                printf("%d ", arr[i][j]);
                i--; 
                j++;
            }
        }
        // === 情况 B：奇数层，往左下走 ===
        else
        {
            int i, j;

            // 起点：上边界或右边界
            if (sum < n)
            {
                i = 0;        // 在上边界
                j = sum;
            }
            else
            {
                i = sum - (n - 1);  // 在右边界
                j = n - 1;
            }

            // 开始往左下走：行增加，列减小
            while (i < n && j >= 0)
            {
                printf("%d ", arr[i][j]);
                i++;
                j--;
            }
        }
    }

    printf("\n");
    return 0;
}
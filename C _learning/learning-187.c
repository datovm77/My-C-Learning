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
            
            // 【关键】用 if-else 确定起点 i
            if (sum < n)
            {
                i = sum; // 没到底，起点行就是 sum
            }
            else
            {
                i = n - 1; // 到底了，起点行只能是最后一行
            }
            
            j = sum - i; // 确定了 i，j 自然就是 sum - i

            // 开始往右上走：行减小，列增加
            // 只要不撞天花板(i>=0) 且 不撞右墙(j<n)
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

            // 【关键】用 if-else 确定起点 i
            if (sum < n)
            {
                i = 0; // 没到右边，起点行是 0
            }
            else
            {
                i = sum - (n - 1); // 到右边了，起点行要往下挪
            }

            j = sum - i; // 确定了 i，j 自然就是 sum - i

            // 开始往左下走：行增加，列减小
            // 只要不撞地板(i<n) 且 不撞左墙(j>=0)
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
#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);

    int arr[15][15];
    int num = 1;
    // 定义边界
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;

    while(num<=n*n)
    {
        // 1. 从左到右填充上边 (保持行不变，列增加)
        for(int i = left;i<=right;i++) arr[top][i] = num++;
        top++;

        // 2. 从上到下填充右边 (保持列不变，行增加)
        for(int i = top;i<=bottom;i++) arr[i][right] = num++;
        right--;

        // 3. 从右到左填充下边 (保持行不变，列减小)
        for(int i = right;i>=left;i--) arr[bottom][i] = num++;
        bottom--;

        // 4. 从下到上填充左边 (保持列不变，行减小)
        for(int i = bottom;i>=top;i--) arr[i][left] = num++;
        left++;
    }
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            printf("%3d",arr[i][j]);
        }
        printf("\n");
    }
}
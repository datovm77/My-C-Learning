#include<stdio.h>

int main()
{
    int m, n;
    printf("Input m, n: ");
    // 建议用空格隔开输入，比较通用。如果你习惯用逗号，可以把 "%d %d" 改回 "%d,%d"
    scanf("%d %d", &m, &n); 

    int arr[m][n];
    int max;
    int row, col;

    for(int i = 0; i < m; i++)
    {
        for(int j = 0; j < n; j++)
        {
            // 1. 读入当前这个数
            scanf("%d", &arr[i][j]);
            
            // 2. 立即处理
            // 如果是全场第一个数 (i=0且j=0)，直接让它当初始擂主
            if(i == 0 && j == 0)
            {
                max = arr[i][j];
                row = 1;
                col = 1;
            }
            // 否则，如果后面进来的数比当前擂主大，就篡位
            else if(arr[i][j] > max)
            {
                max = arr[i][j];
                row = i + 1; // 记录行号
                col = j + 1; // 记录列号
            }
        }
    }

    printf("Input %d*%d array: \n", m, n);
    printf("max=%d, row=%d, col=%d\n", max, row, col);

    return 0;
}
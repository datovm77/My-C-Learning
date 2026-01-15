#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
    int m, n;
    if (scanf("%d %d", &m, &n) != 2) return 0; // 养成检查输入的好习惯

    int arr[m][n];
    int max_val; // 改个名字，更贴切
    int row = 0, col = 0; // 初始化为0，防止第一个数就是最大值时出错

    for(int i = 0; i < m; i++)
    {
        for(int k = 0; k < n; k++)
        {
            scanf("%d", &arr[i][k]);
            
            // 如果是第一个数，直接初始化为擂主
            if (i == 0 && k == 0)
            {
                max_val = arr[0][0];
                row = 0; // 【关键修正】
                col = 0; // 【关键修正】
            }
            // 如果发现绝对值更大的，挑战擂主
            else if(abs(arr[i][k]) > abs(max_val))
            {
                max_val = arr[i][k];
                row = i;
                col = k;
            }
        }
    }

    printf("%d %d %d\n", row + 1, col + 1, max_val);

    return 0;
}
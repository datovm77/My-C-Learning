#include <stdio.h>
// 不懂
int main()
{
    int n;
    int a[20][20];
    scanf("%d", &n);

    int num = 1; // 填入的数字

    // s 是斜线层数，即坐标和 (i+j)
    // 范围是从 0 到 2*n - 2
    for (int s = 0; s <= 2 * n - 2; s++)
    {

        int i_start, i_end;

        // --- 第一步：确定这一轮循环 i 的起点和终点 ---

        // 分情况 1：奇数层，方向向下 (行号 i 逐渐变大)
        if (s % 2 != 0)
        {
            if (s < n)
            {
                // 上半个三角形：从第0行开始，直到第s行
                i_start = 0;
                i_end = s;
            }
            else
            {
                // 下半个三角形：受列号限制，i 不能太小
                // i 最小只能是 s - (n - 1)
                i_start = s - n + 1;
                i_end = n - 1; // 最大只能到最后一行
            }

            // 执行循环：i 从小到大
            for (int i = i_start; i <= i_end; i++)
            {
                int j = s - i; // 算出对应的列
                // 【核心】如果要标准蛇形，写 a[i][j]
                // 【核心】如果要水平翻转，写 a[i][n - 1 - j]
                a[i][n - 1 - j] = num++;
            }
        }
        // 分情况 2：偶数层，方向向上 (行号 i 逐渐变小)
        else
        {
            if (s < n)
            {
                // 上半个三角形：从第s行往回走到第0行
                i_start = s;
                i_end = 0;
            }
            else
            {
                // 下半个三角形：只能从最后一行 n-1 开始往回走
                // 走到 s - (n - 1) 就要停，不然列号就爆了
                i_start = n - 1;
                i_end = s - n + 1;
            }

            // 执行循环：i 从大到小
            for (int i = i_start; i >= i_end; i--)
            {
                int j = s - i;
                a[i][n - 1 - j] = num++;
            }
        }
    }

    // --- 打印输出 ---
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%3d", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}
#include <stdio.h>

int main() {
    int n, k, i, j;
    int a[15][15], b[15][15]; // a是主数组，b是旋转用的辅助数组
    
    // 1. 输入并生成螺旋矩阵 (核心背诵部分)
    scanf("%d", &n);
    int u = 0, d = n - 1, l = 0, r = n - 1; // 上下左右边界 (up, down, left, right)
    int num = 1;
    
    while (num <= n * n) {
        // 题目要求：从右下角开始，逆时针绕 (上 -> 左 -> 下 -> 右)
        for (i = d; i >= u && num <= n*n; i--) a[i][r] = num++; r--; // 向上，右壁缩进
        for (j = r; j >= l && num <= n*n; j--) a[u][j] = num++; u++; // 向左，上壁缩进
        for (i = u; i <= d && num <= n*n; i++) a[i][l] = num++; l++; // 向下，左壁缩进
        for (j = l; j <= r && num <= n*n; j++) a[d][j] = num++; d--; // 向右，下壁缩进
    }

    // 2. 处理旋转次数 (万能公式)
    scanf("%d", &k);
    k = (k % 4 + 4) % 4; // 无论k是正负，都转化为顺时针旋转0~3次

    // 3. 执行旋转 (简单粗暴法)
    while (k--) {
        // 把 a 旋转存入 b
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                b[j][n - 1 - i] = a[i][j]; // 核心旋转公式
        
        // 把 b 倒回 a，准备下一次旋转或输出
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                a[i][j] = b[i][j];
    }

    // 4. 输出
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            printf("%d ", a[i][j]);
        printf("\n");
    }
    return 0;
}
#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0; // 增加读取检测，养成好习惯

    int count = 0; // 记录输出了多少种方案

    // x 代表5分硬币的数量
    // 题目要求5分从少到多，所以从1开始增加
    // 为什么 x <= 12 ? 因为 4x + y = 50，如果 x=13，4*13=52，y就成负数了，不可能
    for (int x = 1; x <= 12; x++) {
        
        // 根据数学推导公式：4x + y = 50 -> y = 50 - 4x
        int y = 50 - 4 * x; 
        
        // 剩下的就是1分硬币，总数100 - x - y
        int z = 100 - x - y;

        // 输出当前方案
        printf("%d %d %d\n", x, y, z);
        
        count++; // 计数器+1
        
        // 如果已经输出了 n 种方案，任务完成，直接退出
        if (count == n) {
            return 0;
        }
    }

    return 0;
}
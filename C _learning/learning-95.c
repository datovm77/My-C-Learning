#include <stdio.h>

// 定义汉诺塔的移动函数
// n: 盘子数量
// A: 起始柱子 (Source)
// B: 辅助柱子 (Auxiliary)
// C: 目标柱子 (Target)
void hanoi(int n, char A, char B, char C) {
    // 【递归出口】
    // 如果只剩下一个盘子，直接从 A 移动到 C
    if (n == 1) {
        printf("Move disk 1 from %c to %c\n", A, C);
        return;
    }

    // 【递归式子 / 递归体】
    // 步骤1: 将 A 上面的 n-1 个盘子，借助 C，移动到 B
    hanoi(n - 1, A, C, B);

    // 步骤2: 将 A 上剩下的第 n 个盘子（最大的），直接移动到 C
    printf("Move disk %d from %c to %c\n", n, A, C);

    // 步骤3: 将 B 上面的 n-1 个盘子，借助 A，移动到 C
    hanoi(n - 1, B, A, C);
}

int main() {
    int n = 5; // 警告：如果是64，程序将永远运行下去
    
    // 为了测试效果，建议你先改成 3 或 4 试试
    // int n = 3; 

    printf("Start moving %d disks:\n", n);
    hanoi(n, 'A', 'B', 'C'); // A是起始，B是辅助，C是终点
    
    return 0;
}
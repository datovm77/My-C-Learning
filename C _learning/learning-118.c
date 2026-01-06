#include <stdio.h>
#include <string.h>

int main() {
    char numStr[100];
    int len, i, j;
    int found = 0; // 用于标记是否找到了符合条件的切割

    // 输入一个数
    // printf("请输入一个数: "); // 如果不需要提示语可以将此行注释
    if (scanf("%s", numStr) != 1) {
        return 0;
    }

    len = strlen(numStr);

    // 如果数字只有1位，无法切割，直接error
    if (len < 2) {
        printf("error\n");
        return 0;
    }

    // 遍历所有可能的切割位置
    // i 代表切割点，意味着左边有 i 个字符 (索引 0 到 i-1)
    // i 从 1 开始到 len-1
    for (i = 1; i < len; i++) {
        int sumLeft = 0;
        int sumRight = 0;

        // 计算左半部分的数字之和
        for (j = 0; j < i; j++) {
            sumLeft += numStr[j] - '0'; // 将字符转换为整数
        }

        // 计算右半部分的数字之和
        for (j = i; j < len; j++) {
            sumRight += numStr[j] - '0'; // 将字符转换为整数
        }

        // 检验是否相等
        if (sumLeft == sumRight) {
            // 如果相等，输出切割后的样子
            // 先输出左半部分
            for (j = 0; j < i; j++) {
                printf("%c", numStr[j]);
            }
            printf(" "); // 输出空格
            // 再输出右半部分
            for (j = i; j < len; j++) {
                printf("%c", numStr[j]);
            }
            printf("\n");
            
            found = 1; // 标记已找到
            break;     // 找到一种情况即可跳出循环（若需列出所有情况可去掉break）
        }
    }

    // 如果遍历完所有切割点都没有符合的
    if (found == 0) {
        printf("error\n");
    }

    return 0;
}
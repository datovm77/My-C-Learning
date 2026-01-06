#include <stdio.h>
#include <string.h>

int main() {
    // 题目说长度不超过100，但插入"(max)"后总长度会变长吗？
    // 注意：如果我们只是打印而不修改原数组，数组只需要存原字符串即可，110就够了。
    char str[110];

    // 使用我们约定好的 fgets 标准写法
    while (fgets(str, sizeof(str), stdin) != NULL) {
        
        // --- 步骤1: 去掉换行符 ---
        size_t len = strlen(str);   //size_t关键字，printf("%zu\n", len);
        if (len > 0 && str[len - 1] == '\n') {
            str[len - 1] = '\0';
            len--; // 记得更新长度
        }

        // --- 步骤2: 找出最大字符 ---
        char max = 0; // 初始化为一个很小的数
        for (int i = 0; i < len; i++) {
            if (str[i] > max) {
                max = str[i];
            }
        }

        // --- 步骤3: 打印结果 ---
        for (int i = 0; i < len; i++) {
            printf("%c", str[i]); // 先原样打印当前字符
            
            // 如果当前字符就是最大字符，紧接着打印标记
            if (str[i] == max) {
                printf("(max)");
            }
        }
        
        // 处理完一组数据后，记得换行
        printf("\n");
    }

    return 0;
}
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    int n;
    char str[60];

    if (scanf("%d", &n) != EOF) {
        getchar(); // 同样需要吃掉数字后的换行符

        while (n--) {
            // 使用更安全的 fgets 替代 gets
            if (fgets(str, sizeof(str), stdin) != NULL) {
                
                // 【重点】去掉 fgets 读入的末尾换行符
                size_t len = strlen(str);
                if (len > 0 && str[len - 1] == '\n') {
                    str[len - 1] = '\0';
                    len--; // 更新长度，防止逻辑判断出错
                }

                // 如果去掉换行后是空行
                if (len == 0) {
                    printf("no\n");
                    continue;
                }

                int is_valid = 1;
                // 1. 检查首字符
                if (!(isalpha(str[0]) || str[0] == '_')) {
                    is_valid = 0;
                } else {
                    // 2. 检查后续字符
                    for (int i = 1; i < (int)len; i++) {
                        if (!(isalnum(str[i]) || str[i] == '_')) {
                            is_valid = 0;
                            break;
                        }
                    }
                }

                if (is_valid) printf("yes\n");
                else printf("no\n");
            }
        }
    }
    return 0;
}
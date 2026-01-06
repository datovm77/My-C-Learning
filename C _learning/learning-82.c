#include <stdio.h>

int main() {
    char ch;
    int num = 0;

    ch = getchar();        // 先读取第一个字符

    while (ch != '#') {    // 检查是否结束
        if (ch >= 'a' && ch <= 'z') {
            putchar(ch);
            num++;
        } else if (ch >= 'A' && ch <= 'Z') {
            putchar(ch);
            num++;
        }

        ch = getchar();    // 继续读取
    }

    if (num == 0) {
        printf("-1");
    } else {
        printf(" %d", num);
    }

    return 0;
}

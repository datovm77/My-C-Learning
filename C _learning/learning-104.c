#include <stdio.h>

int main() {
    int hour, minute;
    char ch;

    // 输入时间部分
    scanf("%d:%d", &hour, &minute);

    // 读取后续字符，跳过可能存在的空格
    // 循环读取直到读到的不是空格
    do {
        ch = getchar();
    } while (ch == ' ');

    // 逻辑处理
    if (ch == 'p' || ch == 'P') {
        // PM的情况
        if (hour != 12) {
            hour += 12;
        }
    } else {
        // AM的情况 (假设非P即A)
        if (hour == 12) {
            hour = 0;
        }
    }

    // 输出结果
    // %02d 表示输出整数，不足2位时前面补0，比如 9:01 会变成 09:01，0:00 会变成 00:00
    // 这是24小时制的标准格式
    printf("%02d:%02d\n", hour, minute);

    return 0;
}
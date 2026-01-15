#include <stdio.h>

int main() {
    int hour, minute;
    char ch;

    // 1. 输入时间部分
    // scanf 会自动解析 12:30 这样的格式
    scanf("%d:%d", &hour, &minute);

    // 2. 读取 AM/PM 字符
    // 【优化点】：注意 %c 前面的那个空格！
    // 它的作用完全等同于你之前的 do-while 循环，会自动跳过数字后面的所有空格
    scanf(" %c", &ch);

    // 3. 逻辑处理 (保持你的原逻辑不变)
    if (ch == 'p' || ch == 'P') {
        // PM 下午逻辑：
        // 如果不是12点（比如 1PM），就+12变成 13
        // 如果是12点（12PM），那就是中午12点，保持不变
        if (hour != 12) {
            hour += 12;
        }
    } 
    else {
        // AM 上午逻辑：
        // 如果是12点（12AM），那就是午夜0点
        // 其他情况（比如 9AM），保持不变
        if (hour == 12) {
            hour = 0;
        }
    }

    // 4. 输出结果
    // %02d 保证个位数补零，例如 9:5 会变成 09:05
    printf("%02d:%02d\n", hour, minute);

    return 0;
}
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fp = fopen("D:\\show.txt", "r");
    if (!fp) { perror("文件打开失败"); return 1; }

    char line[256];
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);  // UTF-8字符串整体输出，不切割
    }

    fclose(fp);
    return 0;
}
#include<stdio.h>

int main()
{
    // 打开文件
    FILE *file = fopen("D:\\show.txt","r");
    
    // 检查文件是否成功打开
    if(file == NULL) {
        printf("无法打开文件！\n");
        return 1;
    }
    
    // 修正：添加括号确保先赋值再比较
    int c;
    while((c = fgetc(file)) != -1)  // 或者使用 EOF
    {
        printf("%c", c);
    }
    
    fclose(file);  // 记得关闭文件
    return 0;
}
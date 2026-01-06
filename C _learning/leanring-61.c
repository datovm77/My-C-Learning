#include<stdio.h>

int main()
{
    char ch;
    int num;
    scanf("%c",&ch);
    scanf("%d",&num);
    
    if (ch <= 'z' && ch >= 'a')
    {
        // 小写字母处理
        int shift = num % 26;  // 实际移动位数（考虑循环）
        char result = ch + shift;
        if (result > 'z')
        {
            result = 'a' + (result - 'z' - 1);  // 超出部分从头开始
        }
        printf("%c", result);
    }
    else if (ch <= 'Z' && ch >= 'A')
    {
        // 大写字母处理
        int shift = num % 26;  // 实际移动位数（考虑循环）
        char result = ch + shift;
        if (result > 'Z')
        {
            result = 'A' + (result - 'Z' - 1);  // 超出部分从头开始
        }
        printf("%c", result);
    }
    else if (ch <= '9' && ch >= '0')
    {
        // 数字处理
        printf("%d", (ch - '0') + num);
    }
    else
    {
        // 其他字符原样输出
        printf("%c", ch);
    }
    
    return 0;
}
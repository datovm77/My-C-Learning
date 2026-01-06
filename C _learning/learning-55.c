#include<stdio.h>
#include<string.h>
//统计字符串的字符类型个数
int main()
{
    printf("请输入一个字符串 \n");
    char str[100];
    scanf("%s",str);
    // printf("%s",str);
    int bigcount = 0;
    int smallcount = 0;
    int numbercount = 0;

    for(int i = 0;i < strlen(str);i++)
    {
        char c = str[i];
        if(c >= 'a' && c <= 'z')
        {
            smallcount++;
        }
        else if(c >= 'A' && c <= 'Z')
        {
            bigcount++;
        }
        else if(c >= '0' && c <= '9')
        {
            numbercount++;
        }
    }

    printf("有%d个小写字符\n",smallcount);
    printf("有%d个大写字符\n",bigcount);
    printf("有%d个数字字符\n",numbercount);

    return 0;
}
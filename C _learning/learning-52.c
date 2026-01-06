#include<stdio.h>
int main()
{
    char str[100];
    printf("开始录入字符： \n");
    scanf("%s",str);
    printf("接受到的字符串为：%s \n",str);
    //遍历数组
    char *p = str;
    while(1)
    {
        //char c = *p;
        if(*p == '\0')
        {
            break;
        }
        printf("%c\n",*p);
        p++;
    }
    return 0;
}
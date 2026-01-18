#include<stdio.h>
#include<ctype.h>
//isspace 判断字符是否为空白字符
//toupper 如果 ch 是小写字母，转为大写；如果是大写字母或标点符号，保持不变
int main()
{
    int ch;
    int flag = 1;

    while((ch = getchar())!=EOF)
    {
        if(ch=='\n')
        {
            printf("\n");
            flag = 1;
        }
        else if(isspace(ch))
        {
            printf("%c",ch);
            flag = 1;
        }
        else
        {
            if(flag==1)
            {
                printf("%c",toupper(ch));
                flag = 0;
            }
            else{
                printf("%c",ch);
            }
        }
    }


    return 0;
}
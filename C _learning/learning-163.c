#include<stdio.h>
#include<string.h>
#include<ctype.h>
//汉字处理，错误演示
int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    for(int i = 0;i<n;i++)
    {
        char str[1000];
        int len;
        if(fgets(str,sizeof(str),stdin)!=NULL)
        {
            len = strlen(str);
            if(len>0&&str[len-1]=='\n')
            {
                str[len-1] = '\0';
                len--;
            }
            int count = 0;
            for(int i = 0;i<len;i++)
            {
                if(isascii(str[i]))
                {
                    count++;
                }
            }
            int han = (len-count)/3;
            printf("%d\n",han);
        }
    }


    return 0;
}
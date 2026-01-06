#include<stdio.h>
#include<ctype.h>
//include
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
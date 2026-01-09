#include<stdio.h>
#include<string.h>  //strcmp 和 strcpy 函数

//strcmp函数:
//返回int 返回 前面字符串-后面字符串 的值

int main()
{
    int n;
    scanf("%d",&n);
    char str[n][80];

    for(int i = 0;i<n;i++)
    {
        scanf("%s",&str[i]);
    }
    int max = 0;
    int max_index = 0;
    for(int i = 0;i<n;i++)
    {
        if(strlen(str[i])>max)
        {
            max = strlen(str[i]);
            max_index = i;
        }
    }

    printf("The longest is: %s",str[max_index]);


    return 0;
}


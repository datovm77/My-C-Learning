#include<stdio.h>
#include<string.h>  //strcmp 和 strcpy 函数
#include<stdlib.h>
//strcmp函数:
//返回int 返回 前面字符串-后面字符串 的值
int cmp(const void *a,const void *b)
{
    return strcmp((char*)a,(char*)b);
}
int main()
{
    char str[5][80];

    for(int i = 0;i<5;i++)
    {
        scanf("%s",&str[i]);
    }
    qsort(str,5,sizeof(str[0]),cmp);
    printf("After sorted:\n");
    for(int i = 0; i < 5; i++)
    {
        printf("%s\n", str[i]);
    }

    return 0;
}


//字符串数组
//字符串底层：就是字符数组 
//也就是把多个 字符数组 放进一个大的 字符数组中（二维数组）
#include<stdio.h>
int main()
{
    char strArr[5][100] = 
    {
        "zhangsan",
        "lisi",
        "wangwu",
        "zhaoliu",
        "qianqi"

    };
    //遍历二维数组
    for(int i = 0; i < 5; i++)
    {
        char *str = strArr[i];
        printf("%s\n",str);
    }

    return 0;
}
#include<stdio.h>
int main()
{
    //ASCII码表中'a'的10进制为97
    char c1 = 'a';
    int i = 'a' + 1;
    printf("%d \n", i);//输出98
    printf("%d \n", c1);//输出97
    printf("%c \n", c1);//输出 a
    

    return 0;
}
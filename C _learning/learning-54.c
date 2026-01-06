#include<stdio.h>
#include<string.h>
int main()
{   
    printf("strlen函数的调用\n");
    char* str1 = "abc" ;//放在只读常量区,会复用
    char str2[100] = "abc";
    char str3[5] = {'l','o','v','e','\0'};
    //一个中文两个字节，英文一个
    // int len1 = strlen(str1);//3
    // int len2 = strlen(str2);//3
    // int len3 = strlen(str3);//4

    // printf("%d\n",len1);
    // printf("%d\n",len2);
    // printf("%d\n",len3);

    printf("--------------------\n");
    printf("strcat函数的调用\n");
    //把第二个字符串的全部内容，拷贝到第一个字符串的末尾
    //  前提一：第一个字符串可以被修改
    //  前提二：第一个字符串空间足够
    // strcat(str2,str3);
    // printf("%s\n",str2);//abclove
    // printf("%s\n",str3);//love

    printf("--------------------\n");
    printf("strcpy函数的调用\n");
    //strcpy(str2,str3);
    //把第二个字符串的所有内容，完整得覆盖到字符串一
    // printf("%s\n",str2);//love
    // printf("%s\n",str3);//love

    printf("--------------------\n");
    printf("strcmp函数的调用\n");
    //完全一样：返回0   有一个不一样非零
    int res = strcmp(str1,str2);
    printf("%d\n",res);

return 0;
}
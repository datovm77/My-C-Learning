#include<stdio.h>
int main()
{
    //转义符号  \
    
    printf("\" \n");  //把 " 变成一个普通的双引号，然后打印"
    printf("\\"); // 打印 \

    //打印文件路径
    char *file = "C:\\Users\\datovm\\OneDrive\\文档\\show.txt";
    printf("%s \n",file);
    return 0;

}
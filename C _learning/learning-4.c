#include<stdio.h>
int main()
{
    //数字直接运算
    printf("%d \n", 3 + 4);
    printf("%d \n", 3 - 4);
    printf("%d \n", 3 * 4);

    printf("%.2lf \n", 1.1 + 2.2);
    printf("%.2lf \n", 1.1 * 2.2);
    printf("%.2lf \n", 1.1 - 2.2);

    //变量运算
    int a = 3;
    int b = 4;
    printf("%d \n", a + b);

    return 0;
}

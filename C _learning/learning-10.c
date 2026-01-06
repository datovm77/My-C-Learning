#include<stdio.h>
int main()
{
   // ++ :变量中的值+1        -- ：变量中的值-1
    int a = 10;
    a++;
    printf("%d \n",a);//输出11 

    //单独使用：++或者--在变量前后没有区别

    //参与计算
    //1.先用后加
    int a = 10;
    int b = a++;//此时a=11.b=10
    //2.先加后用
    int c = 10;
    int d = ++c;//此时两个变量都是11

    
    return 0;
}
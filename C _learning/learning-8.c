#include<stdio.h>
int main()
{
    int b = 65536;
    short i = (short)b;
    printf("%d \n",i);//输出0
    
    //当short char类型的数据在运算的时候，会转为int ，再进行计算
    short s1 = 10;
    short s2 = 20;
    short s3 = (int)s1 + s2;//错误的格式
    short s4 = (short)(s1 + s2) ;//正确的
    printf("%zu \n",sizeof((int)s1 + s2)); //输出4
    printf("%zu \n",sizeof((short)(s1 + s2))); //输出2
    
    return 0;
}
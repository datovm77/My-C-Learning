#include<stdio.h>
int main()
{
    //1.数字相加（隐式转换）
    short a = 10;
    int b = a;  //赋值时自动把取值范围转换
    printf("%d \n",sizeof(a)); //输出2
    printf("%d \n",sizeof(b)); //输出4

    int c = 10;
    double d = 12.3;
    double e = c + d; //double > float > long long>long .... 
    //int e = c + d; 这个会报错

    short f = 10;
    short h = 10;
    int g = f + h;//short char类型的数据在运算的时候，会转为int ，再进行计算
    
    //char类型的相加
    char c1  = 'a' ;
    char c2  = 'b';
    int c3 = c1 +c2;
    printf("%d \n",c1 + c2); //输出195
    printf("%d \n",c3); //输出195



    return 0;
}

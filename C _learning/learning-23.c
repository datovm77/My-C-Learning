#include<stdio.h>
#include<math.h>
int main()
{
    //1.pow幂函数
    double a = pow(2,3);
    printf("%lf \n",a);

    //2.平方根
    double b = sqrt(9);
    printf("%lf \n",b);

    //3.向上取整
    double c = ceil(12.3);
    printf("%lf \n",c);
    
    //4.向下取整
    double d = floor(12.3);
    printf("%lf \n",d);

    //5.绝对值
    double e = fabsf(-23.4);
    printf("%lf \n",e);
    return 0;
}
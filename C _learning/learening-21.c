#include<stdio.h>
#include<math.h>
int main()
{    
    //公式：Π/4 = 1- 1/3 +1/5 - 1/7...
    //目的：计算Π的值
    int de,flag,i;
    double eps,item,pi;
    printf("请输入精度要求: \n");
    scanf("%lf",&eps);
    //循环初始化
    i = 1; //表示项数
    flag = 1;  //表示正负 1为正，-1为负
    pi = 0; //表示Π除以4
    de = 1;//表示分母
    item = 1.0; //表示第一项
    while(fabs(item)>=eps)
    {
        pi = pi + item;
        i++ ;
        flag = -flag;
        de = de + 2;
        item = flag*1.0/de ;
    }
    pi = pi + item;
    pi = pi*4;
    printf("pi = %.4f \n", pi);
    printf("i = %d \n",i);


    return 0;
}
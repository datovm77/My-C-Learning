#include <stdio.h>

int getRemainder(int num1, int num2);

int main()
{
    int a = 25;
    int b = 7;
    int res ;
    res = getRemainder(a, b);
    if(res<0)
    {
        printf("报错！！");
    }
    else{
        printf("获取到的余数为: %d\n", res);
    }
    
    return 0;
}

int getRemainder(int num1, int num2)
{   
    if(num2==0)
    {
        return -1;
    }
    int res = num1 % num2;
    return res;
}

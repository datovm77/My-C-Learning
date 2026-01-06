#include<stdio.h>
int main()
{
    int a = 3;
    int b = 2;
    if(a>b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    printf("a是%d b是%d",a,b);


    return 0;
}
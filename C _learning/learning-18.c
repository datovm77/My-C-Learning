#include<stdio.h>
int main()
{
    double zhi = 0.1;  //纸
    int times = 0;
    while(zhi <= 8844430)
    {
        zhi = zhi * 2;
        times++;
    }
    printf("需要折叠%d次\n",times);

    return 0;
}
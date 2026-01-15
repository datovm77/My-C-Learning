#include<stdio.h>

int judge_su(int number) {
    // 1. 特判小于等于 3 的数
    if (number <= 1) return 0; // 1 及以下不是素数
    if (number <= 3) return 1; // 2 和 3 是素数

    // 2. 特判能被 2 或 3 整除的数（这是 6k±1 法的前提）
    if (number % 2 == 0 || number % 3 == 0) return 0;

    // 3. 此时只需要检查 5, 11, 17... (6k-1) 和 7, 13, 19... (6k+1)
    // 循环步长设为 6
    // 用 i * i <= number 代替 sqrt，效率更高且避免浮点误差
    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) {
            return 0;
        }
    }

    return 1;
}


int main()
{
    int x,y;
    while(scanf("%d %d",&x,&y) != EOF)
    {
        if(y==0&&x==0)
        {
            return 0;
        }
        int flag = 0;
        for(int i = x;i<=y;i++)
        {
            int cal_result = i*i + i + 41;
            if(judge_su(cal_result) == 0)
            {
                flag = 1;
                printf("Sorry\n");
                break;
            }
        }
        if(!flag)
        {
            printf("OK\n");
        }
    }
    return 0;
}
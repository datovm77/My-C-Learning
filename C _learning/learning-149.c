#include<stdio.h>

int main()
{
    int n;
    if(scanf("%d",&n) != 1) return 0;

    int arr[20]; // 稍微开大一点
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    // 初始化：假设最大值就是第一个元素（解决了单个元素和初始值问题）
    long long all_max = arr[0]; 

    for(int i = 0; i < n; i++)
    {
        long long current_product = 1; // 累乘的基数设为1
        for(int j = i; j < n; j++) // j 从 i 开始，包含了“单个元素”的情况
        {
            current_product *= arr[j];
            
            // 每次乘完都比较一次
            if(current_product > all_max)
            {
                all_max = current_product;
            }
        }
    }

    // 根据你原代码的逻辑：如果结果是负数输出0？还是直接输出最大值？
    // 通常题目是直接输出最大值。如果你原题要求负数输0，保留下面的判断：
    if(all_max >= 0) 
        printf("%lld\n", all_max);
    else 
        printf("0\n");

    return 0;
}
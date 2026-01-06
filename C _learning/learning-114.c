//插入排序——优化后
#include<stdio.h>

// 把返回类型改为 void，因为你不需要返回数值
void Insertion_Sort(int arr[], int len)
{
    // 从第 1 个元素开始（第 0 个默认有序）
    for(int j = 1; j < len; j++)
    { 
        int temp = arr[j]; // 摸牌
        int i = j - 1;     // 看前一张牌
        
        // 核心优化：While 循环
        // 翻译：只要 i 没越界 (i >= 0) 并且 前面的牌比 temp 大 (arr[i] > temp)
        // 注意：这里用 > 而不是 >=，保证了稳定性
        while(i >= 0 && arr[i] > temp)
        {
            arr[i+1] = arr[i]; // 挪动
            i--;               // 继续看更前面的一张
        }

        // 循环结束只有两种可能：
        // 1. i < 0 (temp是最小的，插在头)
        // 2. arr[i] <= temp (找到了比temp小的数，插在它后面)
        // 无论哪种，都是插在 i+1 的位置
        arr[i+1] = temp; 
    } 
}

int main()
{
    int arr[] = {8, 4, 5, 7, 1, 3, 6, 2};
    int len = sizeof(arr) / sizeof(arr[0]);
    
    Insertion_Sort(arr, len);

    for(int i = 0; i < len; i++) printf("%d ", arr[i]);
    printf("\n");

    return 0;
}
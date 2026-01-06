#include <stdio.h>
#include <stdlib.h> // 需要 malloc

// 1. 合并函数：将 arr[L..M] 和 arr[M+1..R] 合并
// 注意：你需要一个临时数组 temp 来辅助
void merge(int arr[], int L, int M, int R) {
    // 1. 定义三个指针
    // i 从 L 开始（左半边起点）
    // j 从 M+1 开始（右半边起点）
    // k 指向临时数组 temp 的起点（通常用 0 或 L）
    int *i = &arr[L];   //左边的终点是M
    int *j = &arr[M+1];  //右边的终点是R
    // 2. 动态开辟一个 temp 数组（或者在外部开辟传进来）
    // 大小是多少？ (R - L + 1)--->数组的元素个数？
    int *q = malloc((R - L + 1)*sizeof(int));
    int *q_temp = q;
    // 3. while循环比较：谁小取谁，放入 temp
    int i_move = 0;  //左起点
    int j_move = 0;  //右起点
    while(i_move<(M-L+1) && j_move < (R-M))
    {
        if(*i > *j)
        {
            *q_temp = *j;
            q_temp++;
            j++;
            j_move++;
        }
        else if(*i < *j)
        {
            *q_temp = *i;
            q_temp++;
            i++;
            i_move++;
            
        }
        else 
        {
            *q_temp = *i;
            q_temp++;
            i++;
            i_move++;
        }
    }
    // 4. while循环收尾：左边如果有剩余，全抄过去
    while(i_move<(M-L+1))
    {
        *q_temp = *i;
        q_temp++;
        i++;
        i_move++;
    }
    // 5. while循环收尾：右边如果有剩余，全抄过去
    while(j_move < (R-M))
    {
        *q_temp = *j;
        q_temp++;
        j++;
        j_move++;
    }
    // 6. 【重要】把 temp 里的有序数据，拷贝回原数组 arr 对应的位置
    for(int k = 0;k<=R-L;k++)
    {
        arr[L+k] = q[k];
    }
    free(q);
}

// 2. 递归排序函数
void mergeSort(int arr[], int L, int R) {
    // 递归终止条件：如果 L == R，说明只剩一个数，不用排了，直接返回
    if (L == R) 
    {
        return;
    }

    // 1. 找中点
    int M = L + (R - L) / 2; // 刚学的防溢出！

    // 2. 递归排左边 (L 到 M)
    mergeSort(arr, L, M);

    // 3. 递归排右边 (M+1 到 R)
    mergeSort(arr, M + 1, R);

    // 4. 左右都排好了，合并它们
    merge(arr, L, M, R);
}

int main() {
    int arr[] = {8, 4, 5, 7, 1, 3, 6, 2};
    int len = sizeof(arr) / sizeof(arr[0]);
    
    mergeSort(arr, 0, len - 1);
    
    // 打印看看对不对
    for(int i=0; i<len; i++) printf("%d ", arr[i]);
    return 0;
}
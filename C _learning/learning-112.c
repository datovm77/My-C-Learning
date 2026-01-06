#include <stdio.h>
#include <stdlib.h>
//算法：归并排序
// 标准版 Merge：使用纯下标逻辑
void merge(int arr[], int L, int M, int R) {
    // 1. 定义三个用于遍历的下标（就像三个游标）
    int i = L;      // 左半区的起点
    int j = M + 1;  // 右半区的起点
    int k = 0;      // 临时数组 temp 的当前填坑位置

    // 2. 开辟临时数组
    // 这种写法比 malloc 更清晰，算出总共需要多少个位置
    int size = R - L + 1;
    int *temp = (int *)malloc(size * sizeof(int));
    if (temp == NULL) return; // 习惯，检查内存申请是否成功

    // 3. 双方 PK：谁小谁进 temp
    while (i <= M && j <= R) {
        if (arr[i] <= arr[j]) { // 加个 = 号，保证算法的稳定性（相同元素不交换顺序）
            temp[k++] = arr[i++]; 
            // 上面这行相当于：temp[k] = arr[i]; k++; i++; 
        } else {
            temp[k++] = arr[j++];
        }
    }

    // 4. 左边如果有剩余，全抄过去
    while (i <= M) {
        temp[k++] = arr[i++];
    }

    // 5. 右边如果有剩余，全抄过去
    while (j <= R) {
        temp[k++] = arr[j++];
    }

    // 6. 把 temp 里的数据，原样抄回 arr 的对应位置
    // 注意：arr 是从 L 开始更新的，而 temp 是从 0 开始存的
    for (k = 0; k < size; k++) {
        arr[L + k] = temp[k];
    }

    // 7. 释放内存
    free(temp);
}

void mergeSort(int arr[], int L, int R) {
    if (L == R) {
        return;
    }

    int M = L + (R - L) / 2;

    mergeSort(arr, L, M);
    mergeSort(arr, M + 1, R);

    merge(arr, L, M, R);
}

int main() {
    int arr[] = {8, 4, 5, 7, 1, 3, 6, 2};
    int len = sizeof(arr) / sizeof(arr[0]);
    
    mergeSort(arr, 0, len - 1);
    
    for(int i = 0; i < len; i++) printf("%d ", arr[i]);
    printf("\n");
    return 0;
}
#include <stdio.h>
#include <stdlib.h>

// qsort 需要的比较函数
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

int main() {
    int arr[] = {10, 3, -5, 2, 8, 3, 5, -5, 10, 100};
    int n = 10;

    // 1. 先排序 (时间复杂度 O(N log N))
    qsort(arr, n, sizeof(int), compare);
    // 排序后：-5 -5 2 3 3 5 8 10 10 100

    // 2. 遍历去重 (时间复杂度 O(N))
    int newIndex = 0; // 慢指针，指向去重后的数组末尾
    for (int i = 0; i < n; i++) {
        // 如果是第一个元素，或者当前元素不等于前一个存入的元素
        if (i == 0 || arr[i] != arr[i-1]) {
            arr[newIndex] = arr[i];
            newIndex++;
        }
    }

    // 输出结果
    printf("去重后有 %d 个元素:\n", newIndex);
    for (int i = 0; i < newIndex; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
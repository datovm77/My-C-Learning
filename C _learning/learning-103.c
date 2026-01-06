#include <stdio.h>

// 这是一个通用的交换函数
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// === 快速排序核心代码 ===
// arr: 数组
// left: 左边界下标 (一开始是 0)
// right: 右边界下标 (一开始是 n-1)
void quick_sort(int arr[], int left, int right) {
    // 1. 递归结束条件（如果数组只有一个数，或者左边比右边大了，就不用排了）
    if (left >= right) {
        return;
    }

    // 2. 准备工作
    int i = left;       // 左哨兵
    int j = right;      // 右哨兵
    int pivot = arr[left]; // 选最左边的数为基准

    // 3. 哨兵出发！只要 i 和 j 没相遇，就一直走
    while (i < j) {
        
        // 【重要】右哨兵 j 先走！
        //相遇点的数，必须比基准数小!
        // 只要 j 没碰到 i，并且 arr[j] 比基准大（或者相等），就继续往左走
        while (i < j && arr[j] >= pivot) {
            j--;
        }

        // 左哨兵 i 后走
        // 只要 i 没碰到 j，并且 arr[i] 比基准小（或者相等），就继续往右走
        while (i < j && arr[i] <= pivot) {
            i++;
        }

        // 如果停下来了，且没相遇，说明找到了要交换的两个“刺头”
        if (i < j) {
            swap(&arr[i], &arr[j]);
        }
    }

    // 4. 当循环结束，说明 i 和 j 相遇了。
    // 这时候要把基准数(arr[left]) 和 相遇点(arr[i]) 交换
    // 这样基准数就到了中间
    swap(&arr[left], &arr[i]);

    // 5. 递归（分治）
    // 处理基准数左边的一堆
    quick_sort(arr, left, i - 1);
    // 处理基准数右边的一堆
    quick_sort(arr, i + 1, right);
}

// === 测试用的 Main 函数 ===
int main() {
    int arr[] = {6, 1, 2, 7, 9, 3, 4, 5, 10, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("排序前: ");
    for (int k = 0; k < n; k++) printf("%d ", arr[k]);
    printf("\n");

    // 调用快排，范围是 0 到 n-1
    quick_sort(arr, 0, n - 1);

    printf("排序后: ");
    for (int k = 0; k < n; k++) printf("%d ", arr[k]);
    printf("\n");

    return 0;
}
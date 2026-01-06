#include <stdio.h>
#include <stdlib.h> // abs 和 qsort 需要此头文件

// qsort 的比较函数
// 返回值 > 0 表示 a 排在 b 后面
// 返回值 < 0 表示 a 排在 b 前面
int cmp(const void *a, const void *b) {
    int a1 = *(int *)a;
    int b1 = *(int *)b;
    // 按照绝对值从大到小排序
    // 如果 abs(y) > abs(x)，返回正数，y 会排在 x 前面,也就是a在b前
    return abs(b1) - abs(a1);//降序
    //return abs(a) - abs(b);//升序
}

int main() {
    int n;
    while (scanf("%d", &n) == 1 && n != 0) { // 合并判断逻辑
        int arr[105];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        // 使用系统自带的快速排序
        qsort(arr, n, sizeof(int), cmp);

        for (int i = 0; i < n; i++) {
            if (i > 0) printf(" ");
            printf("%d", arr[i]);
        }
        printf("\n");
    }
    return 0;
}
#include <stdio.h>

int main(void)
{  
    int arr[] = {1, 2, 3, 4, 5};
    int* p1 = arr;
    int* p2 = (int*)&arr;  // 注意：&arr 是 int(*)[5] 类型，不是 int*

    printf("%p\n", (void*)arr);      // 数组首元素地址
    printf("%p\n", (void*)&arr);     // 整个数组的地址
    printf("%p\n", (void*)(&arr+1));     // 整个数组的末尾地址
    printf("%p\n", (void*)(arr+1));     // 整个数组第二个元素的地址
    printf("%d\n", arr[0]);          // 数组第一个元素的值
    printf("%p\n", (void*)(arr + 1)); // 第二个元素的地址
    printf("%p\n", (void*)(&arr + 1)); // 跳过整个数组后的地址

    return 0;
}
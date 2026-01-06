#include <stdio.h>

int main() 
{
    int n;
    printf("输入数字个数: ");
    scanf("%d", &n);
    
    int arr[n];
    printf("输入 %d 个数字: ", n);
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // 冒泡排序
    for(int i = 0; i < n-1; i++) {          // 外层循环：控制排序轮数
        for(int j = 0; j < n-i-1; j++) {    // 内层循环：进行相邻元素比较
            if(arr[j] > arr[j+1]) {         // 如果前一个元素大于后一个元素
                // 交换元素
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    printf("排序后: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
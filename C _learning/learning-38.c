#include <stdio.h>

// 插值查找函数
int interpolationSearch(int arr[], int n, int target) {
    int left = 0;
    int right = n - 1;
    
    // 持续搜索直到找到目标或搜索范围无效
    while (left <= right) {
        // 检查目标是否在当前搜索范围内
        int isInRange = (target >= arr[left] && target <= arr[right]);
        if (!isInRange) {
            break; // 目标不在当前范围内，退出循环
        }
        
        // 如果左右边界值相同，直接检查
        if (arr[left] == arr[right]) {
            if (arr[left] == target) return left;
            break;
        }
        
        // 计算插值位置
        int estimate = left + ((target - arr[left]) * (right - left)) / (arr[right] - arr[left]);
        
        // 确保估算位置在有效范围内
        if (estimate < left) estimate = left;
        if (estimate > right) estimate = right;
        
        // 检查估算位置的值
        if (arr[estimate] == target) {
            return estimate; // 找到目标，返回下标
        }
        else if (arr[estimate] < target) {
            left = estimate + 1; // 在右侧继续搜索
        }
        else {
            right = estimate - 1; // 在左侧继续搜索
        }
    }
    
    return -1; // 未找到目标
}

int main() {
    // 定义有序数组
    int numbers[10] = {2, 5, 8, 12, 16, 23, 38, 45, 67, 89};
    int count = 10;
    int searchNumber;
    
    // 显示数组内容
    printf("数组中的数字：");
    for (int i = 0; i < count; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");
    
    // 获取用户输入
    printf("请输入要查找的数字：");
    scanf("%d", &searchNumber);
    
    // 执行查找
    int position = interpolationSearch(numbers, count, searchNumber);
    
    // 显示结果
    if (position != -1) {
        printf("成功！数字 %d 在数组中的位置是：%d\n", searchNumber, position);
    } else {
        printf("抱歉，数字 %d 不在数组中\n", searchNumber);
    }
    
    return 0;
}
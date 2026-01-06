#include<stdio.h>
//二分查找
// arr[]: 有序数组
// len: 数组长度
// target: 要查找的目标数字
// 返回值: 找到返回下标，找不到返回 -1
int binarySearch(int arr[], int len, int target) 
{
    // 在这里写你的代码
    int left = 0;
    int right = len - 1;
    while( left <= right )
    {
        int mid = left + (right - left) / 2;
        if(arr[mid] > target)
        {
            right = mid - 1;
        }
        else if(arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            return mid;
        }
    }
    return -1;
}

int main() {
    int nums[] = {1, 3, 5, 7, 9, 11};
    int len = sizeof(nums) / sizeof(nums[0]);
    int target = 7;

    int index = binarySearch(nums,len,target);
    printf("下标是%d",index);
}
#include<stdio.h>
int main()
{
    int arr[5] = {4,1,5,2,3};
    //使用选择排序
    int len = sizeof(arr) / sizeof(int) ;
    for(int i = 0; i < len - 1; i++)
    {
        //i：表示数组中的每一个索引
        //第一轮：i = 0

        for(int j = i + 1; j < len ; j++)
        {
            if(arr[i] > arr[j])
            {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        //遍历数组
        
    }
    for(int i = 0; i < len; i++)
        {
            printf("%d ",arr[i]);
        }
    return 0;
}
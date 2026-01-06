#include<stdio.h>
int main()
{
    int arr[5] = {3,5,2,4,1};
    int len = sizeof(arr) / sizeof(int);

    //利用冒泡排序，把数据按照升序进行排序
    for(int i = 0; i < len - 1;i++)  //外循环为四次
    {
        for(int j = 0; j < len - 1 - i; j++)  //循环次数会改变
        {
            if(arr[j]>arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    //遍历数组
    printf("排序后的数组为: ");
    for(int i = 0; i < len;i++)
    {
        printf("%d ",arr[i]);
    }


    return 0;
}
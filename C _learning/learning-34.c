#include<stdio.h>

void printArr(int arr[],int len);

int main()
{
    int arr[5] = {0};
    int len = sizeof(arr) / sizeof(arr[0]);
    //键盘录入数据
    for(int i = 0; i < len; i++)
    {
        printf("请输入第%d个整数: \n",i+1);
        scanf("%d",&arr[i]);   
    }

    //遍历数组
    printArr(arr,len);

    //反转数组
    int i = 0;  //注意：这里的都是i与j都是索引
    int j = len - 1;
    while( i < j )
    {
        //交换
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }

     //遍历数组
    printArr(arr,len);

    return 0 ;
}

void printArr(int arr[],int len)
{
    for(int i = 0; i < len; i++)
    {
        printf("%d \n",arr[i]);
    }
}
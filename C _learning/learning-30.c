#include<stdio.h>
void getMaxAndMin(int arr[],int len,int* max,int* min);
int main()
{
    int arr[] = {0,2,3,4,5,6,7,8,9,10};
    int len = sizeof(arr) / sizeof(int);

    //初始化max和min
    int max = arr[0];
    int min = arr[0];

    //调用函数求最大值与最小值
    getMaxAndMin(arr,len,&max,&min);

    printf("数组最大值为: %d \n",max);
    printf("数组最大值为: %d \n",min);

    return 0;
}

void getMaxAndMin(int arr[],int len,int* max,int* min)
{
    for(int i = 1;i < len; i++)
    {
       if(arr[i]>*max)
       {
        *max = arr[i];
       }
       if(arr[i]<*min)
       {
        *min = arr[i];
       }
    }
}
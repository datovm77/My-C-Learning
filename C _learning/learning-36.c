//打乱数据
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
int main()
{
    int arr[9] = {1,2,3,4,5,6,7,8,9};
    int len = sizeof(arr) / sizeof(arr[0]);
    //生成随机数
    srand(time(NULL));
    for(int i = 0; i < len; i++)
    {
        int index = rand() % len ;//从索引0-8中产生随机数
        //打乱
        int temp = arr[i] ;
        arr[i] = arr[index];
        arr[index] = temp ;
    }

    //遍历数组，输出打印
    printf("打乱后的数组为: \n");
    for(int i = 0; i < len ; i++)
    {
        printf("%d",arr[i]);
    }


    return 0 ;
}
//二分查找
#include<stdio.h>
int find(int arr[],int len,int num) ;
int main()
{
    //定义数组
    int arr[] = {7,23,79,81,103,127,134,147};
    int len = sizeof(arr) / sizeof(arr[0]);
    
    //定义变量表示我要查找的数据
    int num = 134;

    find(arr,len,num);

    printf("我要查找的数据的索引是:%d\n",find(arr,len,num)) ;

    return 0;
}

int find(int arr[],int len,int num)  //返回值为函数的索引
{
    //查找到范围
    int min = 0;
    int max = len - 1;

    while(min <= max)
    {

        int mid = (min + max) / 2;  //注意：这里的mid min max是索引
        //使用arr[mid]和num进行比较
        if(arr[mid] < num)
        {
            min = mid + 1;
        }
        else if(arr[mid] > num)
        {
            max = mid - 1;
        }
        else
        {
            return mid;  //找到了，返回索引
        }
    }
    //如果找不到，即min > max，返回-1
    return -1;

}
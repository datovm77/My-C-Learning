#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int contains(int arr[],int len,int num);

int main()
{   
    //1.定义数组
    int arr[10] ={0};
    int len = sizeof(arr) / sizeof(arr[0]);
    //生成10个1-100之间的随机数
    //生成种子
    srand(time(NULL));
    //生成随机数
    for (int i = 0; i < len; )
    {
        int num = rand() % 100 + 1;

        int flag = contains(arr,len,num);

        if(!flag) //如果flag为0，表示return 0，即数组中没有重复的，那么!flag为1，即为真。然后运行if，存入数据。
        {
            arr[i] = num;
            i++;  //只有存入了数据，i才会自增
        }

    }
    //打印数据
    printf("数组中的随机数为: \n");
    for(int i = 0; i < len ; i++)
    {
        printf("%d \n",arr[i]);
    }

    //求和
    int sum = 0;
    for(int i = 0;i<len;i++)
    {
        sum = sum + arr[i];
    }
    //求平均数
    double avg = sum / len;
    //找出小于平均数的个数
    int count = 0;
    printf("平均数为: %f \n",avg);
    for(int i = 0; i < len ; i++)
    {
        if(arr[i] < avg)
        {
            count++;
        }
    }
    printf("小于平均数的个数为: %d \n",count);
}

int contains(int arr[],int len,int num)
{
    for(int i = 0; i < len; i++)
    {
        if(arr[i] == num)
        {
            return 1;
        }
    }
    return 0;
}
/*
    动态内存分配函数一览(调用stdlib.h)
    malloc  : memory allocation     – 申请一块连续未初始化的空间
    calloc  : contiguous allocation – 申请一块连续并已清零的空间
    realloc : re-allocation         – 调整已分配空间的大小
    free    : free                  – 释放已分配的空间
 */
#include<stdio.h>
#include<stdlib.h>
int main()
{
    //利用函数申请连续空间并赋值初始值：返回空间首地址
    int *p = calloc(10,sizeof(int)); //运行效率不如malloc

    //遍历数组
    for(int i = 0; i < 10; i++)
    {
       //printf("%d \n",*(p+i)); 
       printf("%d \n",p[i]); //都是0
    }

    return 0;
}
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
    //利用函数申请连续空间：返回空间首地址
    // malloc(100); //100个字节，25个int
    int *p = malloc(10*sizeof(int));//申请空间，存储100个int字节

    //利用循环写入数据
    for(int i = 0; i < 10; i++)
    {
        // *(p+i) = (1 + i)*10;
        p[i] = (i + 1) * 10;//因为是连续空间，所以可以看成数组
    }

    //遍历数组
    for(int i = 0; i < 10; i++)
    {
       //printf("%d \n",*(p+i)); 
       printf("%d ",p[i]); 
    }
    //扩容
    printf("\n");
    printf("-------------------------------------------扩容后\n");
    int *pp = realloc(p,20*sizeof(int));
    for(int i = 0; i < 20; i++)
    {
       //printf("%d \n",*(p+i)); 
       printf("%d ",p[i]); //后面多出很多没定义的数据
    }

    //释放空间
    free(pp);

    printf("\n");
    printf("-------------------------------------------释放空间后\n");
    for(int i = 0; i < 20; i++)
    {
       //printf("%d \n",*(p+i)); 
       printf("%d ",p[i]); 
    }
    return 0;
}
#include<stdio.h>
#define MAXN 10
int main(void)
{
    int i,index,k,n,temp;
    int a[MAXN];
    
    printf("输入一个数字n: \n");
    scanf("%d",&n);
    printf("你需要输入 %d 个数字 \n",n);
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    
    for(k=0;k<n-1;k++)
    {
        index = k;
        for(i=k+1;i<n;i++)  //假如n = 5，第一轮i=1
        {
           if(a[i] < a[index])  //初始 i = k+1  index = k
           {
              index = i;
           }  
        }
        temp = a[index];  //让一个临时值为最小值(a[index])
        a[index] = a[k];  //令这个最小值a[index]为a[k]
        a[k] = temp;      //总之让最小的回到最左边
    }
    //输出那个数组元素的值
    printf("分类后: \n");
    for(i=0;i<n;i++)
    {
        printf(" %d ",a[i]);
    }
    printf("\n");

    return 0 ;
}
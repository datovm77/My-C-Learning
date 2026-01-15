#include<stdio.h>
//快慢指针去重
int main()
{
    int arr[] = {1,3,3,4,5,8,8,8,11,42,60,60,78,78};
    int newIndex = 0;
    int len = sizeof(arr) / sizeof(arr[0]);
    for(int i = 0;i<len;i++)
    {
        if(i==0||arr[i]!=arr[i-1])
        {
            arr[newIndex] = arr[i];
            newIndex++;
        }
    }


    printf("去重后有 %d 个元素:\n", newIndex);
    for (int i = 0; i < newIndex; i++) 
    {
        printf("%d ", arr[i]);
    }




    return 0;
}

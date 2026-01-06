#include <stdio.h>

int main()
{
    // 利用指针遍历二维数组

    // 1.定义一个二维数组  
    
    int arr1[5] = {1,2,3,4,5};  
    int arr2[5] = {11,22,33,44,55}; 
    int arr3[5] = {111,222,333,444,555} ; 
   
    int* arr[5] = {arr1,arr2,arr3};
    //获取指针
    int** p = arr;
    //遍历数组
    for(int i = 0;i < 3;i++)
    {
        for(int j = 0;j < 5;j++)
        {
            printf("%d ",*(*p+j));
        }
        printf("\n");
        p++;
    }

    return 0;
}
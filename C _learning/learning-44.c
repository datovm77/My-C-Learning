#include<stdio.h>
int main()
{
    //二维数组：把多个小数组，放入一个大数组
    //三维数组：把多个二维数组，放入一个大数组....依次类推四维，五维
    //格式一：arr[m][n] = m表示二维数组的长度，n表示一个一维数组的长度

    // int arr[3][3] = 
    // {
    //     {1,2,3},
    //     {4,5,6},
    //     {7,8,9}
    // };

    //格式二：
    int arr1[3] = {1,2,3};
    int arr2[5] = {6,7,8,9,0};
    int arr3[6] = {66,77,8,88,9,0};
    int* arr4[3] = {arr1,arr2,arr3};

    int len1 = sizeof(arr1) / sizeof(int);
    int len2 = sizeof(arr2) / sizeof(int);
    int len3 = sizeof(arr3) / sizeof(int);

    int lenArr[3] = {len1,len2,len3};

    //遍历索引：利用索引
    for (int i = 0; i < 3;i++)
    {
        for(int j = 0; j < lenArr[i] ; j++)
        {
            printf("%d ",arr4[i][j]);
        }

        printf("\n");
    }

    return 0;
}
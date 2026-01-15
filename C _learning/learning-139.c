#include<stdio.h>

int main()
{
    int arr1[20] ;
    int arr2[20] ;
    int num1;
    int num2;
    scanf("%d",&num1);
    for(int i = 0;i<num1;i++)
    {
        scanf("%d",&arr1[i]);
    }
    getchar();
    scanf("%d",&num2);
    for(int i = 0;i<num2;i++)
    {
        scanf("%d",&arr2[i]);
    }

    //开始计较数据
    int index = 0;
    int arr3[40];
    for(int i = 0;i<num1;i++)
    {
        int j = 0;
        for(j;j<num2;j++)
        {
            if(arr1[i]==arr2[j])
            {
                break;
            }
        }
        if(j==num2)
        {
            arr3[index] = arr1[i];
            index++;
        }
    }
    for(int i = 0;i<num2;i++)
    {
        int k = 0;
        for(k;k<num1;k++)
        {
            if(arr2[i]==arr1[k])
            {
                break;
            }
        }
        if(k==num1)
        {
            arr3[index] = arr2[i];
            index++;
        }
    }
    for(int i = 0;i<index;i++)
    {
        //printf("%d ",arr3[i]);
        for(int j = i+1;j<index;j++)
        {
            if(arr3[i]==arr3[j])
            {
                for(int h = j+1;h<index;h++)
                {
                    arr3[h-1] = arr3[h];
                }
                index--;
                j--;
            }
        }
    }
    // printf("%d\n",index);
    for(int i = 0;i<index;i++)
    {
        if(i>0)
        {
            printf(" ");
        }
        printf("%d",arr3[i]);
    }
    return 0;
}


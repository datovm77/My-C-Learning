#include<stdio.h>
void swap(int *a,int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int n;
    scanf("%d",&n);
    int arr[11] = {0};
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int max = arr[0];
    int min = arr[0];
    int min_index = 0;
    int max_index = 0;
    for(int j = 1;j<n;j++)
    {
        if(arr[j]>max)
        {
            max = arr[j];
            max_index = j;
        }
        if(arr[j]<min)
        {
            min = arr[j];
            min_index = j;
        }
    }

    swap(&arr[0],&arr[min_index]);
    if(max_index==0)
    {
        swap(&arr[min_index],&arr[n-1]);
    }
    else{
        swap(&arr[max_index],&arr[n-1]);
    }
    for(int i = 0;i<n;i++)
    {
        if(i>0)
        {
            printf(" ");
        }
        printf("%d",arr[i]);
    }
    return 0;
}


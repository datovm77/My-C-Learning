#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int min = arr[0];
    for(int j = 1;j<n;j++)
    {
        if(arr[j]<min)
        {
            min = arr[j];
        }
    }
    printf("%d\n",min);




}
#include<stdio.h>

int main()
{
    int n;
    scanf("%d",&n);
    int arr[15];
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int number;
    scanf("%d",&number);
    int index = n-1;
    while(index >= 0&&arr[index]>number)
    {
        arr[index+1] = arr[index];
        index--;
    }
    arr[index+1] = number;
    for(int i = 0;i<=n;i++)
    {
        if(i>0)
        {
            printf(" ");
        }
        printf("%d",arr[i]);
    }
    return 0;
}


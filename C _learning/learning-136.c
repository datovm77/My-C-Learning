#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int arr[n-1];
    for(int i = n-1;i>=0;i--)
    {
        scanf("%d",&arr[i]);
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
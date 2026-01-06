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
    int mark[5000] = {0};
    int sum = 0;
    for(int i = 0;i<n;i++)
    {
        if(mark[arr[i]]==0) 
        {
            mark[arr[i]] = 1;
            sum+=arr[i];
        }
        else if(mark[arr[i]]==1)
        {
            mark[arr[i]] = 2;
            sum-=arr[i];
        }
        
    }
    printf("%d\n",sum);


    return 0;
}
#include<stdio.h>
int main()
{
    int n;
    int arr[105] = {0};
    int check ;
    scanf("%d",&n);
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    scanf("%d",&check);
    int found = 1;
    for(int i = 0;i<n;i++)
    {
        if(arr[i]==check)
        {
            printf("%d\n",i+1);
            found = 0;
            break;
        }
    }
    if(found==1)
    {
        printf("-1\n");
    }
    return 0;
}
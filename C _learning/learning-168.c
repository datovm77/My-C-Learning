#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    
    for(int i = 0;i<n;i++)
    {
        int arr[10];
        for(int j = 0;j<6;j++)
        {
            scanf("%d",&arr[j]);
        }
        int arrr[5] = {0};
        for(int k = 2;k>=0;k--)
        {
            arrr[k] = arr[k]+arr[k+3];
            if(arrr[k]>60)
            {
                arrr[k]-=60;
                arrr[k-1]++;
            }
        }

        for(int p = 0;p<3;p++)
        {
            printf("%d ",arrr[p]);
        }
        printf("\n");
    }


    return 0;
}
#include<stdio.h>
int main()
{
    int arr[110] ;
    int n,m;
    
    while((scanf("%d %d",&n,&m)==2))
    {
        if(n==0&&m==0)
        {
            break;
        }
        for(int i= 0;i<n;i++)
        {
            scanf("%d",&arr[i]);
        }
        int i = n-1;
        while(i>=0 && arr[i]>m)
        {
            arr[i+1]=arr[i];
            i--;    //当arr[i]<=m时或者i<0，退出
        }
        arr[i+1]=m;
        for(int m = 0;m<=n;m++)
        {
            if(m>0)
            {
                printf(" ");
            }
            printf("%d",arr[m]);
        }
        printf("\n");


    }


    return 0;
}
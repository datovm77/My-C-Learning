#include<stdio.h>
int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    getchar();
    int arr[m][n];
    for(int i = 0;i<m;i++)
    {
        for(int j = 0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }

    for(int i = 0;i<m;i++)
    {
        int result = 0;
        for(int j = 0;j<n;j++)
        {
            result = result + arr[i][j] ;
        }
        printf("%d\n",result);
    }

    return 0;
}
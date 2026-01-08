#include<stdio.h>
//杨辉三角
int main()
{
    int n;
    while((scanf("%d",&n))!=EOF)
    {
        if(n==0)
        {
            return 0;
        }
        int arr[30][30];
        for(int i = 0;i<n;i++)  //i是行，j是列
        {
            for(int j = 0;j<=i;j++)
            {
                if(j==0||j==i)
                {
                    arr[i][j] = 1;
                }
                else
                {
                    arr[i][j] = arr[i-1][j-1] + arr[i-1][j];
                } 
                printf("%d", arr[i][j]);
                if(j!=i) printf(" ");
            }
            printf("\n");
        }
    }

    return 0;
}
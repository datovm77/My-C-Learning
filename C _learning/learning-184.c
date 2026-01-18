#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int num = 1;
    int top = 0,left = 0;
    int bottom = n-1,right = n-1;
    int arr[100][100];
    while(num<=n*n)
    {
        
        for(int i = left;i <= right;i++) arr[top][i] = num++;
        top++;

        for(int i = top;i<=bottom;i++) arr[i][right] = num++;
        right--;

        for(int i = right;i>=left;i--) arr[bottom][i] = num++;
        bottom--;

        for(int i = bottom;i>=top;i--) arr[i][left] = num++ ;
        left++;

    }
    // for(int i = 0;i<n;i++)
    // {
    //     for(int j = 0;j<n;j++)
    //     {
    //         printf("%3d ",arr[i][j]);
    //     }
    //     printf("\n");
    // }
    int new_arr[100][100];
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(!(i==j))
            {
                new_arr[j][i] = arr[i][j]; 
            }
        }
    }
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(!(i==j))
            {
                arr[i][j] = new_arr[i][j]; 
            }
        }
    }
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(j>0) printf(" ");
            printf("%d",arr[i][j]);
        }
        printf("\n");
    }


    return 0;
}
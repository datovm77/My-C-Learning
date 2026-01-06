#include<stdio.h>
int main()
{
    int m,n;
    printf("Input m, n:");
    scanf("%d,%d",&m,&n);
    int arr[m][n];
    int row;
    int col;
    int max = -100;

    for(int i = 0;i<m;i++)
    {
        for(int j = 0;j<n;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i = 0;i<m;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if(arr[i][j]>max)
            {
                max = arr[i][j];
                row = i+1;
                col = j+1;
            }
        }
    }
    printf("Input %d*%d array: \n",m,n);
    printf("max=%d, row=%d, col=%d\n",max,row,col);


    return 0;
}
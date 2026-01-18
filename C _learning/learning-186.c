#include <stdio.h>
int main()
{
    int n,m;
    scanf("%d %d",&n,&m);
    int arr[100][100];
    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<m;j++)
        {
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i = 0;i<n;i++)
    {
        int row_min = arr[i][0];
        int row_min_index = 0;
        for(int j = 1;j<m;j++)
        {
            if(arr[i][j]<row_min)
            {
                row_min = arr[i][j];
                row_min_index = j;
            }
        }
        int flag = 1;
        int col = i;
        for(int j = 0;j<n;j++)
        {
            if(arr[j][row_min_index]>row_min)
            {
                flag = 0;
                col = j;
                break;
            }
        }
        if(flag)
        {
            printf("%d (位置: %d, %d)\n",row_min,col,row_min_index);
        }
    }


    return 0;
}
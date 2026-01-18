#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int arr[100][100];
    int num = 1;

    for(int i = 0;i<n;i++)
    {
        for(int j = 0;j<n;j++)
        {
            if((i+1)%2==0) arr[i][n-1-j] = num++;
            else arr[i][j] = num++;
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
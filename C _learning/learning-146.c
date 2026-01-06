#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//关于行 列的算法一
int main(void)
{
    int m,n;//m行   n列
    scanf("%d %d",&m,&n);
    int number = n*m;
    int arr[m][n];
    arr[0][0] = 0;
    //int *p = (int *)malloc(number*sizeof(int));
    int min;
    int hang,lie;
    for(int i = 0;i<m;i++)
    {
        for(int k = 0;k<n;k++)
        {
            scanf("%d",&arr[i][k]);
            if (i==0&&k==0)
            {
                min = arr[0][0];
            }
            
            else if( abs(arr[i][k]) > abs(min))
            {
                min = arr[i][k];
                hang = i;
                lie = k;
            }
        }
    }
    printf("%d %d %d\n",hang+1,lie+1,min);



    return 0;
}
#include<stdio.h>
int main()
{
    int T;
    scanf("%d",&T);
    for(int i = 0;i<T;i++)
    {
        int n;
        scanf("%d",&n);
        int arr[n][n];
        for(int j = 0;j<n;j++)
        {
            for(int h = 0;h<n;h++)
            {
                scanf("%d",&arr[j][h]);
            }
        }
        int yesorno = 1;
        for(int j = 0;j<n;j++)
        {
            for(int h = 0;h<j;h++)
            {
                if(arr[j][h]!=0)
                {
                    yesorno = 0;
                    break;
                }
            }
            if(!yesorno) break;
        }

        if(yesorno)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }


    }



    return 0;
}
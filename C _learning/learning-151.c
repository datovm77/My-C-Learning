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
        // j 是行，h 是列
        // for(int j = 0; j < n; j++)
        // {
        //     // 【关键修改】
        //     // 起点：h = j + 1 (从对角线往右挪一格开始查)
        //     // 终点：h < n     (一直查到这一行的最末尾)
        //     for(int h = j + 1; h < n; h++) 
        //     {
        //         if(arr[j][h] != 0) // 如果在这个禁区发现了非0数
        //         {
        //             yesorno = 0;
        //             break;
        //         }
        //     }
        //     if(!yesorno) break;
        // }

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
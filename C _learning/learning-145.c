#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    //100 50 10 5 2 1
    int n;//表示老师的人数
    while(scanf("%d",&n)==1)
    {
        if(n==0)
        {
            return 0;
        }

        int *p = (int*)malloc(n*sizeof(int));

        for(int i = 0;i<n;i++)
        {
            scanf("%d",&p[i]);
        }

        //输出张数
        int count = 0;
        int arr1[] = {100,50,10,5,2,1};
        for(int i = 0;i<n;i++)
        {
            for(int k = 0;k<6;k++)
            {
                int rest = p[i] / arr1[k];
                if(rest!=0)
                {
                    count+=rest;
                    p[i]-=rest*arr1[k];
                }
            }
        }
        printf("%d\n",count);
        free(p);

    }



    return 0;
}
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int n;
    while((scanf("%d",&n) != EOF))
    {
        if(n==0)
        {
            break;
        }
        int *p = (int *)malloc(n*sizeof(int));
        int min = 32700;
        int num = -1;
        for(int i = 0;i<n;i++)
        {
            scanf("%d",&p[i]);
            if(p[i]<min)
            {
                min = p[i];
                num = i;
            }
        }
        int temp = p[0];
        p[0] = p[num] ;
        p[num] = temp;

        for(int i = 0;i<n;i++)
        {
            if(i<n-1)
            {
                printf("%d ",p[i]);
            }
            if(i==n-1)
            {
                printf("%d\n",p[i]);
            }
        }
        free(p);
    
    }

    return 0;
}
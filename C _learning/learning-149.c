#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    int arr[10] = {0};
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    int all_max = -10;
    for(int i = 0;i<n;i++)
    {
        int max = -10;
        int ji = arr[i];
        for(int j = i+1;j<n;j++)
        {
            ji *= arr[j];
            if(ji>max)
            {
                max = ji;
            }
        }
        if(max>all_max)
        {
            all_max = max;
        }
    }
    if(all_max>=0) printf("%d\n",all_max);
    else printf("0\n");

    return 0;
}
#include<stdio.h>
int main()
{
    int n,m;  //n表示长度，m表示间隔
    int item = 2;
    int arr[105] = {0};
    for(int i = 0;i<100;i++)
    {   
        arr[i] = item;
        item += 2;
    }

    while(scanf("%d %d",&n,&m) == 2)
    {
        int T = n / m;
        int rest = n % m;
        int index = 0;
        if(rest==0)
        {
            for(int i = 0;i<T;i++)
            {
                int sum = 0;
                for(int j = 0;j<m;j++)
                {
                    sum += arr[index];
                    index++;
                }
                if(i<T-1)
                {
                    printf("%d ",sum/m);
                }
                if(i==T-1)
                {
                    printf("%d\n",sum/m);
                }
            }
        }
        if(rest>0)
        {
            for(int i = 0;i<T;i++)
            {
                int sum = 0;
                for(int j = 0;j<m;j++)
                {
                    sum += arr[index];
                    index++;
                }
                printf("%d ",sum/m);

            }
            int sum = 0;
            for(int j = 0;j<rest;j++)
            {
                sum += arr[index];
                index++;
            }
            printf("%d\n",sum/rest);
        }

    }
    





    return 0;
}
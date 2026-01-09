#include<stdio.h>
#include<string.h>
#define OFFSET 10000
#define MAX_SIZE 20005
int arr_map[MAX_SIZE];
int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        if(n==0&&m==0) break;
        memset(arr_map,0,sizeof(arr_map));

        for(int i = 0;i<n;i++)
        {
            int val;
            scanf("%d",&val);
            if(val+OFFSET>=0 && val+OFFSET<MAX_SIZE)
            {
                arr_map[val+OFFSET] = 1;
            }
        }
        for(int i = 0; i < m; i++)
        {
            int val;
            scanf("%d", &val);
            // 如果这个数在A里有（标记为1），把它去掉（标记为0）
            // 这就是 A - B 的过程
            if(val + OFFSET >= 0 && val + OFFSET < MAX_SIZE) {
                arr_map[val + OFFSET] = 0; 
            }
        }
        int found = 0;

        for(int i = 0;i<MAX_SIZE;i++)
        {
            if(arr_map[i]==1)
            {
                int real_val = i - OFFSET;
                printf("%d ",real_val);
                found = 1;
            }
        }
        if(!found)
        {
            printf("NULL\n");
        }

    }

    return 0;
}

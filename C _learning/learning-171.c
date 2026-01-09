#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    int n,m;
    while(scanf("%d %d",&n,&m)!=EOF)
    {
        if(n==0&&m==0) break;


        int A[105],B[105];
        int result[105];
        int count = 0;

        for(int i = 0;i<n;i++) scanf("%d",&A[i]);
        for(int i = 0;i<m;i++) scanf("%d",&B[i]);

        //核心逻辑
        for(int i = 0;i<n;i++)  //找出A有的，B没有的
        {
            int exist_in_B = 0;   
            for(int j = 0;j<m;j++)
            {
                if(A[i]==B[j])
                {
                    exist_in_B = 1;
                    break;
                }
            }
            if(exist_in_B==0)
            {
                result[count] = A[i];
                count++;
            }

        }
        if(count==0) printf("NULL\n");
        else{
            // qsort(数组名, 元素个数, 每个元素的大小, 比较函数)
            qsort(result,count,sizeof(int),cmp);

            for(int i = 0;i<count;i++) printf("%d ",result[i]);

            printf("\n");
        }



    }
    return 0;
}




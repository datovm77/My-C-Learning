#include<stdio.h>
void get_num(int *p);
int main()
{
    int n;//三角形边长的长度
    scanf("%d",&n);
    int count = 0;
    int *p = &count;
    
    for(int i = 0; i < n;i++)  //纵向
    {
        for(int j = 0; j < n - i;j++)//横向
        {
            printf("%02d",*p+1);
            get_num(p);
        }
        printf("\n");
    }

    return 0;
}

void get_num(int *p)
{
    (*p)++;  
}
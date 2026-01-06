#include<stdio.h>
void print_tri(int n,int i,char ch);
int main()
{
    int n;//n是金字塔的层数
    scanf("%d",&n);
    getchar();
    for(int i = 1; i <= n;i++)
    {
        char ch;
        scanf("%c",&ch);
        getchar();
        print_tri(n,i,ch);
    }

    return 0;
}

void print_tri(int n,int i,char ch) //n是总共多少个小金字塔，i是目前到第几个金字塔，ch是组成元素

{
    for(int j = 1;j <= i;j++) //每一个小金字塔的一行
    {
        for(int l = 1;l <= n-j;l++)
        {
            printf(" ");
        }
        for(int k = 1;k <= j;k++)
        {
            printf(" %c",ch);
        }
        printf("\n");

    }
}
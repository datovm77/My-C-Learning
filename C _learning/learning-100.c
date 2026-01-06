#include<stdio.h>

void print_tri(int n, int i, char ch);

int main()
{
    int n;
    if (scanf("%d", &n) != 1) return 0; 

    for(int i = 1; i <= n; i++)
    {
        char ch;
        scanf(" %c", &ch);
        print_tri(n, i, ch);
    }

    return 0;
}

void print_tri(int n, int i, char ch)
{
    // i 代表当前这个小金字塔的高度
    for(int j = 1; j <= i; j++) // j 代表当前金字塔的第几行
    {
        for(int l = 1; l <= n - j; l++)
        {
            printf(" ");
        }

        for(int k = 1; k <= j; k++)
        {
            if (k == 1) {
                // 如果是该行的第一个字符，前面不加空格
                printf("%c", ch);
            } else {
                // 如果是后面的字符，前面加空格
                printf(" %c", ch);
            }
        }
        printf("\n");
    }
}
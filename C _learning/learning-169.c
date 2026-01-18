#include <stdio.h>
int main()
{
    int n, m;
    while ((scanf("%d %d", &n, &m)) != EOF)
    {
        int arr_max[5000] = {0};
        if (n == 0 && m == 0)
        {
            break;
        }
        // int sum = n+m;
        for (int i = 0; i < n; i++)
        {
            int into;
            scanf("%d", &into);
            arr_max[into] = 1;
        }
        for (int i = 0; i < m; i++)
        {
            int into;
            scanf("%d", &into);
            arr_max[into] = 0;
        }
        int first = 1;
        for (int i = 0; i < 5000; i++)
        {
            if (arr_max[i] == 1)
            {
                if (!first)
                    printf(" %d", i);
                else
                {
                    printf("%d", i);
                    first = 0;
                }
            }
        }
        if (first)
        {
            printf("NULL\n");
        }
        else
            printf("\n");
    }

    return 0;
}
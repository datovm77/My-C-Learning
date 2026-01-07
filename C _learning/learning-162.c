#include <stdio.h>
#include <string.h>
int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    for (int i = 0; i < n; i++)
    {
        char str[1000];
        int len;
        if (fgets(str, sizeof(str), stdin) != NULL)
        {
            len = strlen(str);
            if (len > 0 && str[len - 1] == '\n')
            {
                str[len - 1] = '\0';
                len--;
            }
        }
        int end = len - 1;
        int begin = 0;
        int flag = 1;
        // 优化写法
        while (begin < end)
        {
            if (str[begin] != str[end])
            {
                flag = 0;
                break;
            }
            begin++;
            end--;
        }
        if (flag == 1)
        {
            printf("yes\n");
        }
        else
        {
            printf("no\n");
        }
    }

    return 0;
}
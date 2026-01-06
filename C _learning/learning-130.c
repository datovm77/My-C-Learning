#include<stdio.h>
#include<string.h>
int main()
{
    int n;
    scanf("%d",&n);
    int i;
    for(i = 0;i < n;i++)
    {
        char str[100] = {};
        scanf("%s",str);
        //printf("%s\n",str);
        //printf("%d\n",strlen(str));
        int len = strlen(str);
        int count = 0;
        int j;
        for( j = 0;j<len;j++)
        {
            if(str[j]<='9'&&str[j]>='0')
            {
                count++;
            }
        }
        printf("%d\n",count);

    }
    return 0;
}
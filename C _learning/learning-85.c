#include <stdio.h>

int main(void)
{  
    char ch[100];
    int num = 0;

    scanf("%c", &ch[num]);
    while(ch[num] != '\n') 
    {
        num++;
        scanf("%c", &ch[num]);
    }

    int flag = 0;   // 0 表示 yes

    if(num == 18)   // 18 位
    {
        // 前 17 位必须是数字
        for(int i = 0; i < 17; i++)
        {
            if(ch[i] < '0' || ch[i] > '9')
            {
                flag = 1;
            }
        }

        // 第 18 位必须是数字或 X
        if(!((ch[17] >= '0' && ch[17] <= '9') || ch[17] == 'X'))
        {
            flag = 1;
        }
    }
    else
    {
        flag = 1;
    }

    if(flag == 0)
        printf("yes");
    else
        printf("no");

    return 0;
}

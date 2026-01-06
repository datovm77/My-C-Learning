#include <stdio.h>
int main()
{
    int week;

    printf("输入一个1-7的整数：\n");

    scanf("%d", &week);

        switch (week)
        {
        case 1: 
            printf("数学课\n");
            break;
        case 2:
            printf("语文课\n");
            break;
        case 3:
            printf("英语课\n");
            break;
        case 4:
            printf("物理课\n");
            break;
        case 5:
            printf("化学课\n");
            break;
        case 6:
            printf("生物课\n");
            break;
        case 7:
            printf("地理课\n");
            break;
        default:
            printf("输入一个1-7的整数！！\n");
            break;
        }

    return 0;
}
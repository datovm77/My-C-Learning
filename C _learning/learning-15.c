#include <stdio.h>
int main()
{
    /*
       考试奖励：
        95-100 ：自行车有一辆
        90-94：游乐场玩一天
        80-89：变形金刚一个
        80以下：什么都没有
    */

    int score;
    printf("输入成绩： \n");
    scanf("%d", &score);

    if (score >= 0 && score <= 100)
    {
        if (score >= 95)
        {
            printf("奖励自行车一辆\n");
        }
        else if (score >= 90 && score <= 94)
        {
            printf("奖励游乐场玩一天！\n");
        }
        else if (score >= 80 && score <= 89)
        {
            printf("奖励变形金刚一个！ \n");
        }
        else
        {
            printf("什么都没有！ \n");
        }
    }
    else
    {
        // 处理异常数据
        printf("成绩有误！！\n");
    }
    return 0;
}
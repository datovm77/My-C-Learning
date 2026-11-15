// [蓝桥杯 2020 省 B] 跑步锻炼
#include <iostream>
using namespace std;

bool isLeap(int y)
{
    return y % 400 == 0 ||
           (y % 4 == 0 && y % 100 != 0);
}

int daysInMonth(int y, int m)
{
    int days[13] = {
        0, 31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31};

    if (m == 2 && isLeap(y))
        return 29;

    return days[m];
}

void nextDay(int &y, int &m, int &d)
{
    d++;

    if (d > daysInMonth(y, m))
    {
        d = 1;
        m++;

        if (m > 12)
        {
            m = 1;
            y++;
        }
    }
}

int main()
{
    int y = 2000, m = 1, d = 1;
    int weekday = 6;
    int ans = 0;

    while (true)
    {

        // 先计算当前这一天
        if (weekday == 1 || d == 1)
        {
            ans += 2;
        }
        else
        {
            ans += 1;
        }

        // 当前天是最后一天，结束
        if (y == 2020 && m == 10 && d == 1)
        {
            break;
        }

        // 日期和星期同时前进
        nextDay(y, m, d);
        weekday = weekday % 7 + 1;
    }

    cout << ans << '\n';

    return 0;
}
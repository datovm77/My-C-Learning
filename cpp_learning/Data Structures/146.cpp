// P2010 [NOIP 2016 普及组] 回文日期
#include <iostream>
// 原：using namespace std;

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

bool validDate(int y, int m, int d)
{
    if (y < 1 || m < 1 || m > 12)
        return false;

    return d >= 1 && d <= daysInMonth(y, m);
}

int main()
{
    int n;
    std::cin >> n; // 原：cin >> n;

    int ans1 = 0;
    int ans2 = 0;

    for (int y = n / 10000; y <= 9999; y++)
    {

        // 拆分年份的四位数字
        int a = y / 1000;
        int b = y / 100 % 10;
        int c = y / 10 % 10;
        int d = y % 10;

        // 倒序构造月和日
        int m = d * 10 + c;
        int day = b * 10 + a;

        // 必须是合法日期
        if (!validDate(y, m, day))
            continue;

        // 合成八位日期数字
        int date = y * 10000 + m * 100 + day;

        // 要求严格晚于输入日期
        if (date <= n)
            continue;

        // 第一个回文日期
        if (ans1 == 0)
            ans1 = date;

        // ABAB 年份对应 ABABBABA 日期
        if (ans2 == 0 &&
            a == c && b == d && a != b)
        {
            ans2 = date;
        }

        if (ans1 != 0 && ans2 != 0)
            break;
    }

    std::cout << ans1 << '\n'; // 原：cout << ans1 << '\n';
    std::cout << ans2 << '\n'; // 原：cout << ans2 << '\n';

    return 0;
}

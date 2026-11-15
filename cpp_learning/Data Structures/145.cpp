// P8651 [蓝桥杯 2017 省 B] 日期问题
#include <iostream>
#include <iomanip>
#include <set>
#include <tuple>
// 原：using namespace std;

// 判断闰年
bool isLeap(int y)
{
    return y % 400 == 0 ||
           (y % 4 == 0 && y % 100 != 0);
}

// 获取月份天数
int daysInMonth(int y, int m)
{
    int days[13] = {
        0, 31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31};

    if (m == 2 && isLeap(y))
        return 29;

    return days[m];
}

// 判断日期是否合法
bool validDate(int y, int m, int d)
{
    if (y < 1 || m < 1 || m > 12)
        return false;

    return d >= 1 && d <= daysInMonth(y, m);
}

int main()
{
    int a, b, c;
    char s1, s2;

    std::cin >> a >> s1 >> b >> s2 >> c; // 原：cin >> a >> s1 >> b >> s2 >> c;

    std::set<std::tuple<int, int, int>> dates; // 原：set<tuple<int, int, int>> dates;

    // 尝试添加一种日期解释
    auto add = [&](int yy, int m, int d)
    {
        int y;

        if (yy >= 60)
            y = 1900 + yy;
        else
            y = 2000 + yy;

        if (validDate(y, m, d))
        {
            dates.insert({y, m, d});
        }
    };

    // 三种解释
    add(a, b, c);
    add(c, a, b);
    add(c, b, a);

    // 自动按时间排序、去重后输出
    for (auto [y, m, d] : dates)
    {
        // 原：cout << setfill('0') << setw(4) << y << "-"
        //           << setw(2) << m << "-" << setw(2) << d << '\n';
        std::cout << std::setfill('0')
                  << std::setw(4) << y << "-"
                  << std::setw(2) << m << "-"
                  << std::setw(2) << d << '\n';
    }

    return 0;
}

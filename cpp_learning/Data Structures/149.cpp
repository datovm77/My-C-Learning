// P2010 [NOIP 2016 普及组] 回文日期
#include <iostream>

bool isleap(int year)
{
    return year % 400 == 0 || (year % 100 != 0 && year % 4 == 0);
}

int daysinmonth(int y, int m)
{
    int days[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (m == 2 && isleap(y))
    {
        return 29;
    }
    return days[m];
}

bool validdata(int y, int m, int d)
{
    if (y < 1 || m < 1 || m > 12)
        return false;
    return d >= 1 && d <= daysinmonth(y, m);
}

int main()
{
    int begin, end;
    if (!(std::cin >> begin >> end))
        return 0;

    int years_begin = begin / 10000;
    int years_end = end / 10000;

    int sum = 0;
    for (int i = years_begin; i <= years_end; i++)
    {
        int a = i % 10;
        int b = i / 10 % 10;
        int c = i / 100 % 10;
        int d = i / 1000 % 10;

        int m = a * 10 + b;
        int days = c * 10 + d;

        int date = i * 10000 + m * 100 + days;
        if (validdata(i, m, days) && date >= begin && date <= end)
        {
            sum++;
        }
    }

    std::cout << sum << '\n';
}
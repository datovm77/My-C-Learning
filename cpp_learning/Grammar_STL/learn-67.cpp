// 练习CDate类与软件类，闰年判断、天数计算与到期日比较
#include <iostream>
#include <string>
// write-access check: minimal edit

class CDate
{
private:
    int year, month, day;

public:
    CDate(int y, int m, int d);
    bool isLeapYear();
    int getYear();
    int getMonth();
    int getDay();
    int getDayofYear();
};

CDate::CDate(int y, int m, int d)
{
    year = y, month = m, day = d;
}

bool CDate::isLeapYear()
{
    return (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;
}

int CDate::getYear()
{
    return year;
}

int CDate::getMonth()
{
    return month;
}

int CDate::getDay()
{
    return day;
}

int CDate::getDayofYear()
{
    int i, sum = day;
    int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (isLeapYear())
    {
        a[2]++;
    }
    for (i = 0; i < month; i++)
    {
        sum += a[i];
    }
    return sum;
}

class soft_w
{
private:
    std::string name;
    char type;
    CDate deadline;
    char media;

    static bool isLeap(int y)
    {
        return (y % 4 == 0 && y % 100 != 0) || y % 400 == 0;
    }

    static int daysBeforeYear(int y)
    {
        int yy = y - 1;
        return yy * 365 + yy / 4 - yy / 100 + yy / 400;
    }

    static int toSerialDay(int y, int m, int d)
    {
        static int prefix[13] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
        int days = daysBeforeYear(y) + prefix[m] + d;
        if (m > 2 && isLeap(y))
        {
            days += 1;
        }
        return days;
    }

    const char *typeText() const
    {
        if (type == 'O')
        {
            return "original";
        }
        if (type == 'T')
        {
            return "trial";
        }
        return "backup";
    }

    const char *mediaText() const
    {
        if (media == 'D')
        {
            return "optical disk";
        }
        if (media == 'H')
        {
            return "hard disk";
        }
        return "USB disk";
    }


public:
    soft_w(std::string name_out, char type_out, CDate d, char media_out)
        : name(name_out), type(type_out), deadline(d), media(media_out)
    {
    }

    soft_w(const soft_w &other)
        : name(other.name), type('B'), deadline(other.deadline), media('H')
    {
    }

    void print_info()
    {
        std::cout << "name:" << name << '\n';
        std::cout << "type:" << typeText() << '\n';
        std::cout << "media:" << mediaText() << '\n';

        int y = deadline.getYear();
        int m = deadline.getMonth();
        int d = deadline.getDay();

        if (y == 0 && m == 0 && d == 0)
        {
            std::cout << "this software has unlimited use" << '\n';
            return;
        }

        int base = toSerialDay(2015, 4, 7);
        int now = toSerialDay(y, m, d);
        int diff = now - base;

        if (diff < 0)
        {
            std::cout << "this software has expired" << '\n';
        }
        else
        {
            std::cout << "this software is going to be expired in " << diff << " days" << '\n';
        }
    }
};

int main()
{
    int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i)
    {
        std::string name;
        char type, media;
        int year, month, day;

        std::cin >> name >> type >> media >> year >> month >> day;

        CDate deadline(year, month, day);
        soft_w origin(name, type, deadline, media);
        soft_w backup(origin);

        origin.print_info();
        std::cout << '\n';
        backup.print_info();

        if (i != t - 1)
        {
            std::cout << '\n';
        }
    }

    return 0;
}

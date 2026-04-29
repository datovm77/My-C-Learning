// 练习Date日期类，构造函数、getter/setter与日期加一天逻辑
#include <iostream>
#include <iomanip>
class Date
{
private:
    int year, month, day;

public:
    Date()
    {
        year = 1900;
        month = 1;
        day = 1;
    }
    Date(int year, int month, int day) : year(year), month(month), day(day) {}

    int getYear() const
    {
        return year;
    }
    int getMonth() const
    {
        return month;
    }
    int getDay() const
    {
        return day;
    }
    void setDate(int y, int m, int d)
    {
        year = y;
        month = m;
        day = d;
    }
    void print()
    {
        std::cout << "Today is " << year << "/" << std::setfill('0') << std::setw(2) << month << "/" << std::setfill('0') << std::setw(2) << day << std::endl;
    }
    void addOneDay()
    {
        bool isLeapYear = (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
        int maxDay = 31;

        if (month == 2)
        {
            maxDay = isLeapYear ? 29 : 28;
        }
        else if (month == 4 || month == 6 || month == 9 || month == 11)
        {
            maxDay = 30;
        }

        if (day < maxDay)
        {
            ++day;
        }
        else
        {
            day = 1;
            if (month < 12)
            {
                ++month;
            }
            else
            {
                month = 1;
                ++year;
            }
        }

        std::cout << "Tomorrow is " << year << "/" << std::setfill('0') << std::setw(2) << month << "/" << std::setfill('0') << std::setw(2) << day << std::endl;
    }
};

int main()
{
    int n;
    std::cin >> n;

    for (int i = 0; i < n; ++i)
    {
        int year, month, day;
        std::cin >> year >> month >> day;

        Date d1;
        if (i % 2 == 0)
        {
            d1 = Date(year, month, day);
        }
        else
        {
            d1.setDate(year, month, day);
        }

        d1.print();
        d1.addOneDay();
    }
    return 0;
}

#include <iostream>

class Date
{
    int year, month, day;

public:
    Date();
    Date(int y, int m, int d);
    int getYear();
    int getMonth();
    int getDay();
    void setDate(int y, int m, int d);
    void print();
    void addOneDay();
};

Date::Date()
{
    year = 1900;
    month = 1;
    day = 1;
}

Date::Date(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
}

int Date::getYear()
{
    return year;
}

int Date::getMonth()
{
    return month;
}

int Date::getDay()
{
    return day;
}

void Date::setDate(int y, int m, int d)
{
    year = y;
    month = m;
    day = d;
}

void Date::print()
{
    std::cout << "Today is " << year << "/";
    if (month < 10) std::cout << "0";
    std::cout << month << "/";
    if (day < 10) std::cout << "0";
    std::cout << day << std::endl;
}

void Date::addOneDay()
{
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    bool isLeap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    if (isLeap) daysInMonth[2] = 29;
    day++;
    if (day > daysInMonth[month])
    {
        day = 1;
        month++;
        if (month > 12)
        {
            month = 1;
            year++;
        }
    }
}

int main()
{
    int t;
    std::cin >> t;
    for (int i = 0; i < t; i++)
    {
        int y, m, d;
        std::cin >> y >> m >> d;
        Date date;
        if (i % 2 == 0)
            date = Date(y, m, d);
        else
            date.setDate(y, m, d);
        date.print();
        date.addOneDay();
        std::cout << "Tomorrow is " << date.getYear() << "/";
        if (date.getMonth() < 10) std::cout << "0";
        std::cout << date.getMonth() << "/";
        if (date.getDay() < 10) std::cout << "0";
        std::cout << date.getDay() << std::endl;
    }
    return 0;
}

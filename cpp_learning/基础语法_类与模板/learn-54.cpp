// 练习运算符重载，知识点：Student类的日期差比较
#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string name;
    int year, month, day;

    bool isLeapYear(int y) const;
    int daysBeforeYear(int y) const;
    int daysBeforeMonth(int y, int m) const;
    int totalDays() const;

public:
    Student(string n = "", int y = 0, int m = 0, int d = 0);
    int operator-(const Student& obj) const;
    string getName() const;
};

Student::Student(string n, int y, int m, int d)
{
    name = n;
    year = y;
    month = m;
    day = d;
}

bool Student::isLeapYear(int y) const
{
    return (y % 4 == 0 && y % 100 != 0) || (y % 400 == 0);
}

int Student::daysBeforeYear(int y) const
{
    return (y - 1) * 365 + (y - 1) / 4 - (y - 1) / 100 + (y - 1) / 400;
}

int Student::daysBeforeMonth(int y, int m) const
{
    int monthDays[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int sum = 0;

    if (isLeapYear(y))
    {
        monthDays[1] = 29;
    }

    for (int i = 0; i < m - 1; i++)
    {
        sum += monthDays[i];
    }

    return sum;
}

int Student::totalDays() const
{
    return daysBeforeYear(year) + daysBeforeMonth(year, month) + day;
}

int Student::operator-(const Student& obj) const
{
    int difference = totalDays() - obj.totalDays();

    if (difference < 0)
    {
        difference = -difference;
    }

    return difference;
}

string Student::getName() const
{
    return name;
}

int main()
{
    int n;
    cin >> n;

    Student students[100];

    for (int i = 0; i < n; i++)
    {
        string name;
        int year, month, day;
        cin >> name >> year >> month >> day;
        students[i] = Student(name, year, month, day);
    }

    int first = 0, second = 1;
    int minDifference = students[0] - students[1];

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            int difference = students[i] - students[j];

            if (difference < minDifference)
            {
                minDifference = difference;
                first = i;
                second = j;
            }
        }
    }

    cout << students[first].getName() << "和" << students[second].getName()
         << "年龄相差最小，为" << minDifference << "天。" << endl;

    return 0;
}

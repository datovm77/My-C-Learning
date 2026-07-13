#include <iostream>

class Clock
{
private:
    int hour;
    int minute;
    int second;

    void addOneSecond()
    {
        second++;
        if (second == 60)
        {
            second = 0;
            minute++;
            if (minute == 60)
            {
                minute = 0;
                hour++;
                if (hour == 12)
                {
                    hour = 0;
                }
            }
        }
    }

    void subOneSecond()
    {
        second--;
        if (second < 0)
        {
            second = 59;
            minute--;
            if (minute < 0)
            {
                minute = 59;
                hour--;
                if (hour < 0)
                {
                    hour = 11;
                }
            }
        }
    }

public:
    Clock(int h = 0, int m = 0, int s = 0)
    {
        hour = h;
        minute = m;
        second = s;
    }

    friend Clock &operator++(Clock &c);
    friend Clock operator--(Clock &c, int);

    void show() const
    {
        std::cout << hour << ':' << minute << ':' << second << std::endl;
    }
};

Clock &operator++(Clock &c)
{
    c.addOneSecond();
    return c;
}

Clock operator--(Clock &c, int)
{
    Clock old = c;
    c.subOneSecond();
    return old;
}

int main()
{
    int h, m, s;
    std::cin >> h >> m >> s;

    Clock c(h, m, s);

    int t;
    std::cin >> t;
    while (t--)
    {
        int x;
        std::cin >> x;

        if (x > 0)
        {
            while (x--)
            {
                ++c;
            }
        }
        else if (x < 0)
        {
            while (x++)
            {
                c--;
            }
        }

        c.show();
    }

    return 0;
}

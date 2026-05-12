// 练习循环计数器与时钟组合，知识点：继承多态、CyclicCounter、组合设计、虚函数override
#include <iostream>
#include <iomanip>
using namespace std;

// 计数器类
class Counter
{
protected:
    int value;

public:
    Counter(int v = 0) : value(v) {}
    virtual ~Counter() {}
    virtual void increment() { ++value; }
    int getValue() const { return value; }
    void setValue(int v) { value = v; }
};

// 循环计数器类
class CyclicCounter : public Counter
{
    int minValue;
    int maxValue;

public:
    CyclicCounter(int minv, int maxv, int init = 0)
        : Counter(init), minValue(minv), maxValue(maxv)
    {
        if (value < minv)
            value = minv;
        if (value > maxv)
            value = maxv;
    }
    void increment() override
    {
        if (value == maxValue)
            value = minValue;
        else
            ++value;
    }
    int getMin() const { return minValue; }
    int getMax() const { return maxValue; }
};

// 时钟类 (避开 clock/time 系统关键字)
class MyClock
{
    CyclicCounter hour;
    CyclicCounter minute;
    CyclicCounter second;

public:
    MyClock(int h, int m, int s)
        : hour(0, 23, h), minute(0, 59, m), second(0, 59, s) {}

    void tick(int s)
    {
        s %= 86400; // 一天的秒数，避免无谓的大循环
        for (int i = 0; i < s; ++i)
        {
            second.increment(); // 秒加1，利用循环计数器功能
            if (second.getValue() == second.getMin())
            {
                minute.increment();
                if (minute.getValue() == minute.getMin())
                {
                    hour.increment();
                }
            }
        }
    }

    void show() const
    {
        cout << setfill('0') << setw(2) << hour.getValue() << ":"
             << setfill('0') << setw(2) << minute.getValue() << ":"
             << setfill('0') << setw(2) << second.getValue();
    }
};

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int h, m, s, sec;
        cin >> h >> m >> s >> sec;
        MyClock c(h, m, s);
        c.tick(sec);
        c.show();
        cout << endl;
    }
    return 0;
}
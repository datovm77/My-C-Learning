// 练习日期时间格式化输出，setfill与setw控制宽度补零
#include <iostream>
#include <iomanip>

int main()
{
    int n;
    std::cin >> n;
    while (n--)
    {
        int year, mon, day, hour, minute, second;
        std::cin >> year >> mon >> day >> hour >> minute >> second;
        std::cout << year << '-' << std::setfill('0') << std::setw(2) << mon << '-' << std::setfill('0') << std::setw(2) << day << ' ';
        std::cout << std::setfill('0') << std::setw(2)<<hour << ':' << std::setfill('0') << std::setw(2) << minute << ':' << std::setfill('0') << std::setw(2) << second << '\n';
    }

    return 0;
}

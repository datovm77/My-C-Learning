// 练习圆类，计算周长面积与判断点是否在圆内
#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
const double PI = 3.14;

class circle
{
public:
    double x, y;
    double R;
};

void test01()
{
    circle c1;
    std::cin >> c1.x >> c1.y >> c1.R;
    double leng = 2 * PI * (c1.R);
    double s = PI * c1.R * c1.R;
    std::cout << std::fixed << std::setprecision(2) << s << " " << leng << '\n';
    double x, y;
    std::cin >> x >> y;
    double distant = std::sqrt((x - c1.x) * (x - c1.x) + (y - c1.y) * (y - c1.y));
    if (distant <= c1.R)
        std::cout << "yes" << std::endl;
    else
        std::cout << "no" << '\n';
}

int main()
{
    test01();
    return 0;
}

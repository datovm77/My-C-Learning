#include <iostream>
#include <cmath>
class Point
{
private:
    double x, y;

public:
    Point(double xx, double yy) : x(xx), y(yy) {}
    friend double Distance(Point &a, Point &b);
};

double Distance(Point &a, Point &b)
{
    double result = std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
    return result;
}

int main()
{
    int n;
    std::cin >> n;
    int a, b, c, d;
    while (n--)
    {
        std::cin >> a >> b >> c >> d;
        Point p1(a, b);
        Point p2(c, d);
        std::cout << static_cast<int>(Distance(p1, p2)) << '\n';
    }

    return 0;
}
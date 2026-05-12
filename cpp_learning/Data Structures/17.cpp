#include <iostream>
#include <cmath>
#include <iomanip>
class Cpoint
{
protected:
    int x = 0;
    int y = 0;
    Cpoint() = default;
    Cpoint(int x1, int y1) : x(x1), y(y1) {}
};

class Ccircle : public Cpoint
{
protected:
    int r;

public:
    Ccircle() = default;
    // Ccircle(const int &x1, const int &y1, const int &r1) { x = x1; y = y1; r = r1; } // 不规范：基础类型参数用 const 引用收益小，且构造后再赋值不如初始化列表清晰
    Ccircle(int x1, int y1, int r1) : Cpoint(x1, y1), r(r1) {}
    void Print_Cc() const
    {
        // double Area = 3.14 * r * r; // 不规范：3.14 是低精度魔法数字，局部变量命名也不够规范
        constexpr double kPi = 3.14159265358979323846;
        double area = kPi * r * r;
        std::cout << "Circle:(" << x << "," << y << ")," << r << '\n';
        std::cout << "Area:" << std::fixed << std::setprecision(2) << area << '\n';
    }
};

class CCylinder : public Ccircle
{
protected:
    int h;

public:
    // CCylinder(const int &x2, const int &y2, const int &r2, const int &h2) { x = x2; y = y2; r = r2; h = h2; } // 不规范：构造函数体内赋值可用初始化列表替代
    CCylinder(int x2, int y2, int r2, int h2) : Ccircle(x2, y2, r2), h(h2) {}
    void Print_CCy() const
    {
        std::cout << "Cylinder:(" << x << "," << y << ")," << r << "," << h << '\n';
        // double Volume = 3.14 * r * r * h; // 不规范：同样是低精度魔法数字与局部变量命名问题
        constexpr double kPi = 3.14159265358979323846;
        double volume = kPi * r * r * h;
        std::cout << "Volume:" << std::fixed << std::setprecision(2) << volume << '\n';
    }
};

int main()
{
    int x1, y1, r1;
    std::cin >> x1 >> y1 >> r1;
    Ccircle c1(x1, y1, r1);

    c1.Print_Cc();

    int x2, y2, r2, h;

    std::cin >> x2 >> y2 >> r2 >> h;

    CCylinder c2(x2, y2, r2, h);

    c2.Print_CCy();
    return 0;
}

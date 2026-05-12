// 练习2D/3D点距离计算与继承，知识点：基类派生类、初始化列表、const成员函数、std::sqrt
#include <iostream>
#include <cmath>
class C2D
{
private:
    int x = 0;
    int y = 0;

public:
    // C2D() { } // 不规范：默认构造后成员未初始化，值不确定
    C2D() = default;
    C2D(int x1, int y1) : x(x1), y(y1) {}
    void distant_show() const
    {
        // double distant = sqrt(x * x + y * y); // 不规范：应显式使用 std::sqrt，避免命名污染
        double distance = std::sqrt(x * x + y * y);
        std::cout << distance << '\n';
    }
    // int getx() // 不规范：getter 未声明为 const，限制 const 对象调用
    int getx() const
    {
        return x;
    }
    // int gety() // 不规范：getter 未声明为 const，接口语义不清晰
    int gety() const
    {
        return y;
    }
    void setx(int x1)
    {
        x = x1;
    }
    void sety(int y1)
    {
        y = y1;
    }
};

class C3D : public C2D
{
private:
    int z;

public:
    // C3D(int x1, int y1, int z1) { z = z1; C2D::setx(x1); C2D::sety(y1); } // 不规范：先构造后赋值，不如初始化列表直接构造基类和成员
    C3D(int x1, int y1, int z1) : C2D(x1, y1), z(z1) {}

    void show_distant_three() const
    {
        const int x1 = C2D::getx();
        const int y1 = C2D::gety();
        const int z1 = z;
        // std::cout << sqrt(x1 * x1 + y1 * y1 + z1 * z1) << '\n'; // 不规范：未显式使用 std::sqrt
        std::cout << std::sqrt(x1 * x1 + y1 * y1 + z1 * z1) << '\n';
    }
};

int main()
{
    int x1, y1;
    std::cin >> x1 >> y1;
    C2D c1(x1, y1);
    c1.distant_show();

    int x2, y2, z2;
    std::cin >> x2 >> y2 >> z2;
    C3D c2(x2, y2, z2);
    c2.show_distant_three();

    int x3, y3, z3;
    std::cin >> x3 >> y3 >> z3;
    C3D c3(x3, y3, z3);
    c3.show_distant_three();

    c3.distant_show();
    return 0;
}

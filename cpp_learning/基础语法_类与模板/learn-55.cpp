#include <iostream>
class point
{
    int x;
    int y;
    int z;

public:
    point(int X = 0, int Y = 0, int Z = 0)
    {
        x = X;
        y = Y;
        z = Z;
    }
    friend point operator++(point &a);
    friend point operator++(point &, int);
    friend point operator--(point &);
    friend point operator--(point &, int);
    void show()
    {
        std::cout << "x=" << x << ' ' << "y=" << y << ' ' << "z=" << z << std::endl;
    }
};

// 前置的++
point operator++(point &a)
{
    a.x++;
    a.y++;
    a.z++;
    return a;
}

// 后置的++
point operator++(point &a, int)
{
    point b = a;
    a.x++;
    a.y++;
    a.z++;
    return b;
}

// 前置的--
point operator--(point &a)
{
    --a.x;
    --a.y;
    --a.z;
    return a;
}

// 后置的--
point operator--(point &a, int)
{
    point b = a;
    a.x--;
    a.y--;
    a.z--;
    return b;
}

int main()
{
    int x, y, z;
    std::cin >> x >> y >> z;

    point p1(x, y, z), p2;

    p2 = p1++;
    p1.show();
    p2.show();

    p1 = point(x, y, z);
    p2 = ++p1;
    p1.show();
    p2.show();

    p1 = point(x, y, z);
    p2 = p1--;
    p1.show();
    p2.show();

    p1 = point(x, y, z);
    p2 = --p1;
    p1.show();
    p2.show();

    return 0;
}

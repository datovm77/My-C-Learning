#include <iostream>
#include <cstdlib>

using namespace std;

class CPoint
{
private:
    int x;
    int y;

public:
    CPoint(int xValue = 0, int yValue = 0) : x(xValue), y(yValue) {}

    int getX() const
    {
        return x;
    }

    int getY() const
    {
        return y;
    }
};

class CRectangle
{
private:
    CPoint leftPoint;
    CPoint rightPoint;

public:
    CRectangle(int x1, int y1, int x2, int y2) : leftPoint(x1, y1), rightPoint(x2, y2) {}

    bool operator>(const CPoint &p) const
    {
        return p.getX() >= leftPoint.getX() && p.getX() <= rightPoint.getX() &&
               p.getY() <= leftPoint.getY() && p.getY() >= rightPoint.getY();
    }

    bool operator>(const CRectangle &other) const
    {
        CPoint otherLeftTop(other.leftPoint.getX(), other.leftPoint.getY());
        CPoint otherRightBottom(other.rightPoint.getX(), other.rightPoint.getY());
        CPoint otherRightTop(other.rightPoint.getX(), other.leftPoint.getY());
        CPoint otherLeftBottom(other.leftPoint.getX(), other.rightPoint.getY());
        return *this > otherLeftTop && *this > otherRightBottom &&
               *this > otherRightTop && *this > otherLeftBottom;
    }

    bool operator==(const CRectangle &other) const
    {
        return leftPoint.getX() == other.leftPoint.getX() &&
               leftPoint.getY() == other.leftPoint.getY() &&
               rightPoint.getX() == other.rightPoint.getX() &&
               rightPoint.getY() == other.rightPoint.getY();
    }

    bool operator*(const CRectangle &other) const
    {
        int overlapLeft = leftPoint.getX() > other.leftPoint.getX() ? leftPoint.getX() : other.leftPoint.getX();
        int overlapRight = rightPoint.getX() < other.rightPoint.getX() ? rightPoint.getX() : other.rightPoint.getX();
        int overlapTop = leftPoint.getY() < other.leftPoint.getY() ? leftPoint.getY() : other.leftPoint.getY();
        int overlapBottom = rightPoint.getY() > other.rightPoint.getY() ? rightPoint.getY() : other.rightPoint.getY();
        return overlapLeft <= overlapRight && overlapBottom <= overlapTop;
    }

    operator int() const
    {
        return abs(rightPoint.getX() - leftPoint.getX()) * abs(leftPoint.getY() - rightPoint.getY());
    }

    friend ostream &operator<<(ostream &os, const CRectangle &rect)
    {
        os << rect.leftPoint.getX() << " " << rect.leftPoint.getY() << " "
           << rect.rightPoint.getX() << " " << rect.rightPoint.getY();
        return os;
    }
};

int main()
{
    int t, x1, x2, y1, y2;
    cin >> t;
    while (t--)
    {
        cin >> x1 >> y1 >> x2 >> y2;
        CRectangle rect1(x1, y1, x2, y2);
        cin >> x1 >> y1 >> x2 >> y2;
        CRectangle rect2(x1, y1, x2, y2);
        cout << "矩形1:" << rect1 << " " << (int)rect1 << endl;
        cout << "矩形2:" << rect2 << " " << (int)rect2 << endl;
        if (rect1 == rect2)
        {
            cout << "矩形1和矩形2相等" << endl;
        }
        else if (rect2 > rect1)
        {
            cout << "矩形2包含矩形1" << endl;
        }
        else if (rect1 > rect2)
        {
            cout << "矩形1包含矩形2" << endl;
        }
        else if (rect1 * rect2)
        {
            cout << "矩形1和矩形2相交" << endl;
        }
        else
        {
            cout << "矩形1和矩形2不相交" << endl;
        }
        cout << endl;
    }
    return 0;
}

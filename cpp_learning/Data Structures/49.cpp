#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

class Point
{
    double x, y;

public:
    Point()
    {
        x = 0;
        y = 0;
        cout << "Constructor." << endl;
    }
    Point(double x_value, double y_value)
    {
        x = x_value;
        y = y_value;
        cout << "Constructor." << endl;
    }
    Point(const Point &p)
    {
        x = p.x;
        y = p.y;
        cout << "Constructor." << endl;
    }
    ~Point()
    {
        cout << "Distructor." << endl;
    }
    double getX()
    {
        return x;
    }
    double getY()
    {
        return y;
    }
    void setXY(double x1, double y1)
    {
        x = x1;
        y = y1;
    }
    void setX(double x_value) { x = x_value; }
    void setY(double y_value) { y = y_value; }
    double getDisTo(const Point &p)
    {
        double dx = x - p.x;
        double dy = y - p.y;
        return sqrt(dx * dx + dy * dy);
    }
};

int main()
{
    int t;
    if (!(cin >> t))
        return 0;
    while (t--)
    {
        int n;
        cin >> n;
        Point *p = nullptr;
        if (n > 0)
            p = new Point[n];
        for (int i = 0; i < n; i++)
        {
            double xi, yi;
            cin >> xi >> yi;
            p[i].setXY(xi, yi);
        }
        if (n >= 2)
        {
            double maxDist = -1;
            int mi = 0, mj = 1;
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    double d = p[i].getDisTo(p[j]);
                    if (d > maxDist)
                    {
                        maxDist = d;
                        mi = i;
                        mj = j;
                    }
                }
            }
            cout << fixed << setprecision(2) << "The longeset distance is " << maxDist << ",between p[" << mi << "] and p[" << mj << "]." << endl;
        }
        else if (n == 1)
        {
            cout << fixed << setprecision(2) << "The longeset distance is 0.00,between p[0] and p[0]." << endl;
        }
        if (p != nullptr)
        {
            delete[] p;
            p = nullptr;
        }
    }
    return 0;
}

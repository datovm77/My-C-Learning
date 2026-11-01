// P1024 [NOIP 2001 提高组] 一元三次方程求解
#include <iostream>
#include <iomanip>
using namespace std;

double a, b, c, d;

// 计算 f(x) 的值
double f(double x)
{
    return a * x * x * x + b * x * x + c * x + d;
}

int main()
{
    cin >> a >> b >> c >> d;

    cout << fixed << setprecision(2);

    for (int i = -100; i <= 100; i++)
    {

        // 情况1：整数本身就是根
        if (f(i) == 0)
        {
            cout << (double)i << " ";
        }

        // 情况2：根位于两个整数之间
        else if (i < 100 && f(i) * f(i + 1) < 0)
        {
            double l = i, r = i + 1;

            // 二分查找
            while (r - l > 1e-7)
            {
                double mid = (l + r) / 2;

                if (f(l) * f(mid) <= 0)
                {
                    r = mid;
                }
                else
                {
                    l = mid;
                }
            }

            cout << (l + r) / 2 << " ";
        }
    }

    return 0;
}

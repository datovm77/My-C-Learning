// P1024 [NOIP 2001 提高组] 一元三次方程求解
#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
double a, b, c, d;

double cal(double x)
{
    return (1.0 * x * x * x * a + 1.0 * x * x * b + 1.0 * x * c + d);
}

/* 原来的 check：只看函数值是否小于 0，不能确定根在哪一半。
bool check(double x)
{
    double result = cal(x);
    if (result < 0)
        return true;
    return false;
}
*/

// 判断左端点与中点的函数值是否异号。
bool check(double left, double mid)
{
    return (cal(left) < 0) != (cal(mid) < 0);
}

// 按系数的大小判断整数端点是否为根，避免直接比较浮点数。
bool is_root(double x)
{
    double scale = std::abs(a * x * x * x) + std::abs(b * x * x)
                 + std::abs(c * x) + std::abs(d);
    return std::abs(cal(x)) <= 1e-12 * scale;
}

int main()
{
    if (!(std::cin >> a >> b >> c >> d))
        return 0;

    std::cout << std::fixed << std::setprecision(2);

    /* 原来的循环：j 一直向后找，区间可能包含多个根。
    for (int i = -100; i < 100; i++)
    {
        for (int j = i + 1; j <= 100; j++)
        {
            if (cal(i) * cal(j) < 0)
            {
                double l = i * 1.000;
                double r = j * 1.000;

                double result = 0.00;
                while (l <= r)
                {
                    double mid = l + (r - l) / 2.000;
                    if (check(mid))
                    {
                        l = mid + 0.001;
                        result = mid;
                    }
                    else
                        r = mid - 0.001;
                }
                std::cout << std::fixed << std::setprecision(2) << result << '\n';
                i = j;
            }
        }
    }
    */

    for (int i = -100; i < 100; i++)
    {
        double l = i;
        double r = i + 1;

        // 整数端点上的根单独输出，避免漏掉或重复输出。
        bool left_is_root = is_root(l);
        bool right_is_root = is_root(r);
        if (left_is_root)
            std::cout << l << ' ';

        if (!left_is_root && !right_is_root && check(l, r))
        {
            // 原：while (l <= r)，并使用 mid +/- 0.001。
            while (r - l > 1e-8)
            {
                double mid = l + (r - l) / 2.0;
                if (cal(mid) == 0)
                {
                    l = r = mid;
                    break;
                }
                if (check(l, mid))
                    r = mid;
                else
                    l = mid;
            }
            std::cout << (l + r) / 2.0 << ' '; // 原：每个根后输出换行
        }
    }

    if (is_root(100))
        std::cout << 100.0;
    std::cout << '\n';

    return 0;
}

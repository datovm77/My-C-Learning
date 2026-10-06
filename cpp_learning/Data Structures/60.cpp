#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

// 输出多项式
void printPoly(const map<int, int> &poly)
{
    bool first = true;

    // map 默认按照指数从小到大排列
    for (auto &p : poly)
    {
        int exp = p.first;
        int coef = p.second;

        // 系数为 0，不输出
        if (coef == 0)
            continue;

        if (!first)
            cout << " + ";
        first = false;

        // 系数为负数，要加括号
        if (coef < 0)
            cout << "(" << coef << ")";
        else
            cout << coef;

        // 指数不为 0，输出 x^指数
        if (exp != 0)
        {
            cout << "x^";

            // 指数为负数，也要加括号
            if (exp < 0)
                cout << "(" << exp << ")";
            else
                cout << exp;
        }
    }

    cout << endl;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        // 第一个多项式
        int n;
        cin >> n;

        map<int, int> poly1;

        for (int i = 0; i < n; i++)
        {
            int coef, exp;
            cin >> coef >> exp;

            // 相同指数的项直接合并
            poly1[exp] += coef;
        }

        // 第二个多项式
        int m;
        cin >> m;

        map<int, int> poly2;

        for (int i = 0; i < m; i++)
        {
            int coef, exp;
            cin >> coef >> exp;

            poly2[exp] += coef;
        }

        // 输出原来的两个多项式
        printPoly(poly1);
        printPoly(poly2);

        // 两个多项式相加
        map<int, int> result = poly1;

        for (auto &p : poly2)
        {
            result[p.first] += p.second;
        }

        // 输出结果
        printPoly(result);
    }

    return 0;
}
// CSP202412B 梦境巡查
// 暴力枚举初始能量，仅供练习；完整数据见 205.cpp。
#include <iostream>
#include <vector>

using namespace std;

int n;
vector<int> a;
vector<int> b;
vector<int> w;

bool check(int e)
{
    int i = 0;
    while (e >= 0 && i <= n)
    {
        if (e >= a[i])
        {
            e -= a[i];
        }
        else
            return false;
        i++;
        if (i <= n)
            e += b[i];
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;

    a.resize(n + 1);
    b.resize(n + 1);
    for (int i = 0; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }

    for (int i = 1; i <= n; i++)
    {
        int a = b[i];
        b[i] = 0;
        int begin = 0;
        while (!check(begin))
        {
            ++begin;
        }
        b[i] = a;
        w.push_back(begin);
    }
    for (int i = 0; i < n; i++)
    {
        if (i)
            cout << ' ';
        cout << w[i];
    }
    cout << '\n';
    return 0;
}
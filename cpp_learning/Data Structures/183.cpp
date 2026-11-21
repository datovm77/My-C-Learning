// CSP202605A 银行家舍入
#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int n;

    cin >> n;
    vector<double> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    vector<int> ff;

    bool first = true;
    for (const double &x : v)
    {
        int N = (int)x;
        int D = (int)(x * 10) % 10;
        if (D >= 5 && D <= 9)
            N++;
        if (!first)
            cout << ' ';
        first = false;
        cout << N;
    }
    cout << '\n';

    first = true;
    for (const double &x : v)
    {
        int N = (int)x;
        int D = (int)(x * 10) % 10;
        if (D == 5)
        {
            if ((N & 1) != 0)
            {
                N++;
            }
        }
        else if (D >= 6 && D <= 9)
        {
            N++;
        }

        if (!first)
            cout << ' ';
        first = false;
        cout << N;
    }
    cout << '\n';
}
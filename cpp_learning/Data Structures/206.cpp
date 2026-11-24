// CSP202006B 稀疏向量
#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int, int> u_v;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n, a, b;
    cin >> n >> a >> b;
    while (a--)
    {
        int c, d;
        cin >> c >> d;

        u_v[c] = d;
    }

    long long sum = 0;
    while (b--)
    {
        int c, d;
        cin >> c >> d;

        if (u_v[c])
        {
            sum += 1LL * u_v[c] * d;
        }
    }

    cout << sum << '\n';
}
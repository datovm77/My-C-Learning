// P1042 [NOIP 2003 普及组] 乒乓球
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

// limit 表示采用 11 分制还是 21 分制
void solve(const string &s, int limit)
{
    int w = 0, l = 0;

    for (char c : s)
    {
        if (c == 'W')
            w++;
        else if (c == 'L')
            l++;

        // 达到目标分数，且领先至少 2 分
        if ((w >= limit || l >= limit) && abs(w - l) >= 2)
        {
            cout << w << ':' << l << '\n';
            w = 0;
            l = 0;
        }
    }

    // 输出最后一局（即使是 0:0）
    cout << w << ':' << l << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    char c;

    while (cin >> c && c != 'E')
    {
        s += c;
    }

    solve(s, 11);
    cout << '\n';
    solve(s, 21);

    return 0;
}

// CSP202409B 字符串变换
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<char, char> f;
    unordered_map<char, string> cycle;

    // 初始化：默认每个字符映射到自己
    for (int i = 0; i < 128; i++)
    {
        // 等价于 (char)i
        f[char(i)] = char(i);
    }

    string s;
    getline(cin, s);

    int n;
    cin >> n;
    cin.ignore(1024, '\n');

    while (n--)
    {
        string s2;
        getline(cin, s2);
        f[s2[1]] = s2[2];
    }

    // 预处理原字符串中每种字符的循环节
    for (char ch : s)
    {
        // 已经计算过，不需要重复计算
        if (cycle.count(ch))
            continue;

        char cur = ch;

        do
        {
            cycle[ch].push_back(cur);
            cur = f[cur];
        } while (cur != ch);
    }

    int t;
    cin >> t;

    while (t--)
    {
        int k;
        cin >> k;

        string s_t = s;

        for (int i = 0; i < (int)s.size(); i++)
        {
            char ch = s[i];

            s_t[i] = cycle[ch][k % cycle[ch].size()];
        }

        cout << s_t << '\n';
    }

    return 0;
}
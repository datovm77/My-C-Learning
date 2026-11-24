// CSP202409B 字符串变换
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
// 超时做法，只能80分
int main()
{
    unordered_map<char, char> f;
    string s;
    getline(cin, s);

    int len_s = (int)s.size();
    int n;
    cin >> n;
    cin.ignore(1024, '\n');
    while (n--)
    {
        string s2;
        getline(cin, s2);
        f[s2[1]] = s2[2];
    }
    for (int i = 0; i < len_s; i++)
    {
        if (!f[s[i]])
        {
            f[s[i]] = s[i];
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        string s_t = s;
        int tt;
        cin >> tt;

        while (tt--)
        {
            for (int i = 0; i < len_s; i++)
            {
                s_t[i] = f[s_t[i]];
            }
        }
        cout << s_t << '\n';
    }

    return 0;
}
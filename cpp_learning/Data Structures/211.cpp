// CSP201403C 命令行选项
#include <iostream>
#include <string>
#include <sstream>
#include <map>
#include <limits>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    // 代表26个字母的状态
    int type[26] = {};

    for (int i = 0; i < (int)s.size(); i++)
    {
        type[s[i] - 'a'] = 1;
        if (i + 1 < (int)s.size() && s[i + 1] == ':')
        {
            type[s[i] - 'a'] = 2;
            i++;
        }
    }

    int n;
    cin >> n;
    cin.ignore(1024, '\n');
    for (int tc = 1; tc <= n; tc++)
    {
        string line;
        getline(cin, line);

        istringstream iss(line);
        string token;

        iss >> token;
        map<char, string> ans;
        while (iss >> token)
        {
            if ((int)token.size() != 2 || token[0] != '-' || token[1] < 'a' || token[1] > 'z')
                break;
            char ch = token[1];
            if (type[ch - 'a'] == 0)
                break;
            string arg;

            // 带有参数的选项，额外读取一个字符串
            if (type[ch - 'a'] == 2)
            {
                if (!(iss >> arg))
                    break;
            }

            ans[ch] = arg;
        }

        cout << "Case " << tc << ":";

        for (auto &[ch, arg] : ans)
        {
            cout << " -" << ch;

            if (!arg.empty())
                cout << ' ' << arg;
        }
        cout << '\n';
    }

    return 0;
}
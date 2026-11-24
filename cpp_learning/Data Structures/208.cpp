// CSP202409A 密码
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int check(string s)
{
    unordered_map<char, int> ap;
    int len = (int)s.size();
    // 包含字母
    bool has_ab = false;
    // 包含数字
    bool has_num = false;
    // 包含特殊字符
    bool has_sp_char = false;
    // 超过两次
    bool out_two = false;
    for (int i = 0; i < len; i++)
    {
        char c = s[i];
        if (!has_ab)
        {
            if ((c <= 'Z' && c >= 'A') || (c <= 'z' && c >= 'a'))
            {
                has_ab = true;
            }
        }
        if (!has_num)
        {
            if (c <= '9' && c >= '0')
            {
                has_num = true;
            }
        }
        if (!has_sp_char)
        {
            if ((c == '*') || (c == '#'))
            {
                has_sp_char = true;
            }
        }
        ap[c]++;
        if (ap[c] > 2)
        {
            out_two = true;
        }
    }

    if (has_ab && has_num && has_sp_char && (!out_two))
    {
        return 2;
    }
    else if (has_ab && has_num && has_sp_char)
    {
        return 1;
    }

    return 0;
}

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        string s;

        cin >> s;
        cout << check(s) << '\n';
    }

    return 0;
}
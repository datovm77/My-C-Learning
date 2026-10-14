#include <iostream>
#include <string>

// 求最长的、两次出现互不重叠的子串长度。
int longestRepeatedSubstring(const std::string &s)
{
    const int n = static_cast<int>(s.size());
    int best = 0;

    // i、j 是两段子串的起点，且 i < j。
    for (int i = 0; i < n; ++i)
    {
        for (int j = i + 1; j < n; ++j)
        {
            int length = 0;

            // 每次准备增加一个字符，必须同时满足：
            // 1. 第一段的当前字符在 j 前面，保证两段不重叠；
            // 2. 第二段的当前字符仍在字符串内；
            // 3. 两段的当前字符相同。
            while (i + length < j &&
                   j + length < n &&
                   s[i + length] == s[j + length])
            {
                ++length;
            }

            if (length > best)
                best = length;
        }
    }

    return best == 0 ? -1 : best;
}

int main()
{
    int t;
    if (!(std::cin >> t))
        return 0;

    while (t--)
    {
        std::string s;
        std::cin >> s;
        std::cout << longestRepeatedSubstring(s) << '\n';
    }

    return 0;
}

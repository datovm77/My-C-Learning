// P1106 删数问题
#include <iostream>
#include <string>
int main()
{
    std::string s; // 原：int n, k;
    int k;
    if (!(std::cin >> s >> k)) // 原：std::cin >> n >> k
        return 0;

    /* 原来的标记方式：没有逐次删除，而且可能访问 number[-1]。
    std::string s = std::to_string(n);
    std::vector<char> number(s.begin(), s.end());

    int len = static_cast<int>(s.size());
    for (int i = 0; i < len - 1; i++)
    {
        if (number[i] >= number[i + 1])
        {
            number[i] = '*';
        }
    }
    int i = -1;
    while (k--)
    {
        number[i] = '*';
        i--;
    }
    std::string s2;
    s2.assign(number.begin(), number.end());
    s2.erase(std::remove(s2.begin(), s2.end(), '*'), s2.end());
    */

    while (k--)
    {
        int i = 0;
        // 找到第一个大于右边数字的位置；找不到就停在最后一位。
        while (i + 1 < static_cast<int>(s.size()) && s[i] <= s[i + 1])
        {
            i++;
        }
        s.erase(i, 1);
    }

    std::string s2 = s; // 原：从 number 中移除 '*' 后构造 s2。
    while (s2.size() > 1 && s2[0] == '0')
    {
        s2.erase(0, 1);
    }
    std::cout << s2 << '\n';
}

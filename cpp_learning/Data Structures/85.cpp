#include <iostream>
#include <string>
#include <vector>
void arr_next(std::vector<int> &next, std::string s1)
{
    int i = 0;
    int j = -1;
    int len = static_cast<int>(s1.size());
    next.assign(len + 1, 0);
    next[0] = -1;

    while (i < len)
    {
        if ((j == -1) || s1[i] == s1[j])
        {
            i++;
            j++;
            next[i] = j;
        }
        else
        {
            j = next[j];
        }
    }
}

int kmp_cal(const std::vector<int> &next, std::string &S, std::string &T)
{
    int S_len = static_cast<int>(S.size());
    int T_len = static_cast<int>(T.size());

    int i = 0;
    int j = 0;

    while ((i < S_len) && (j < T_len))
    {
        if (j == -1 || S[i] == T[j])
        {
            i++;
            j++;
        }
        else
        {
            j = next[j];
        }
    }

    if (j == T_len)
    {
        return i - j;
    }
    return -1;
}

int main()
{

    int t;
    std::cin >> t;
    while (t--)
    {
        std::string s;
        std::string t;
        std::string replace;
        std::cin >> s >> t >> replace;
        std::vector<int> next;
        arr_next(next, t);

        int result = kmp_cal(next, s, t);

        std::cout << s << '\n';
        if (result != -1)
            s.replace(result, t.size(), replace);
        std::cout << s << '\n';
    }
    return 0;
}

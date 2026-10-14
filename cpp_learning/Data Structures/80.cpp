#include <iostream>
#include <string>
#include <vector>

void getNext(const std::string &T, std::vector<int> &next)
{
    int len = static_cast<int>(T.size());
    int i = 0;
    int j = -1;
    next.assign(len, 0);
    next[0] = -1;

    while (i < len - 1)
    {
        if (j == -1 || (T[i] == T[j]))
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
int kmpSearch(const std::string &S, const std::string &T,
              const std::vector<int> &next)
{
    int mlen = static_cast<int>(S.size());
    int plen = static_cast<int>(T.size());

    int i = 0;
    int j = 0;

    while (i < mlen && j < plen)
    {
        if (j == -1 || S[i] == T[j])
        {
            ++i;
            ++j;
        }
        else
        {
            j = next[j];
        }
    }

    if (j == plen)
        return i - j + 1;
    return 0;
}
int main()
{
    int time;
    std::cin >> time;
    while (time--)
    {
        std::string s;
        std::string t;
        std::cin >> s >> t;
        std::vector<int> next;
        getNext(t, next);
        int result = kmpSearch(s, t, next);
        for (int i = 0; i < static_cast<int>(next.size()); i++)
        {
            std::cout << next[i] << ' ';
        }
        std::cout << '\n';
        std::cout << result << '\n';
    }
    return 0;
}
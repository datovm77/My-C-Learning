// P1042 [NOIP 2003 普及组] 乒乓球
#include <iostream>
#include <vector>
#include <string>
int main()
{
    std::ios::sync_with_stdio(0);
    std::vector<std::string> v;

    std::string s;
    while (std::cin >> s)
    {
        v.push_back(s);
    }

    int W_count = 0;
    int L_count = 0;
    bool end = false;
    for (const auto &x : v)
    {
        int len = static_cast<int>(x.size());

        for (int i = 0; i < len; i++)
        {
            if (x[i] == 'E')
            {
                std::cout << W_count << ':' << L_count << '\n';
                W_count = 0;
                L_count = 0;
                end = true;
                break;
            }
            else if (x[i] == 'W')
            {
                W_count++;
            }
            else if (x[i] == 'L')
            {
                L_count++;
            }
            if (end)
            {
                break;
            }
            if ((W_count >= 11 && W_count - L_count >= 2) || (L_count >= 11 && L_count - W_count >= 2))
            {
                std::cout << W_count << ':' << L_count << '\n';
                W_count = 0;
                L_count = 0;
            }
        }
    }
    std::cout << '\n';
    end = false;
    for (const auto &x : v)
    {
        int len = static_cast<int>(x.size());

        for (int i = 0; i < len; i++)
        {
            if (x[i] == 'E')
            {
                std::cout << W_count << ':' << L_count << '\n';
                W_count = 0;
                L_count = 0;
                end = true;
                break;
            }
            else if (x[i] == 'W')
            {
                W_count++;
            }
            else if (x[i] == 'L')
            {
                L_count++;
            }
            if (end)
            {
                break;
            }
            if ((W_count >= 21 && W_count - L_count >= 2) || (L_count >= 21 && L_count - W_count >= 2))
            {
                std::cout << W_count << ':' << L_count << '\n';
                W_count = 0;
                L_count = 0;
            }
        }
    }
}
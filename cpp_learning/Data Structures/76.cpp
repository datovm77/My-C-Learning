#include <iostream>
#include <string>

int main()
{
    std::ios::sync_with_stdio(0);
    int q;
    std::cin >> q;
    std::string s1;
    std::cin >> s1;
    while (q--)
    {
        int num;
        std::cin >> num;
        if (num == 1)
        {
            std::string s2;
            std::cin >> s2;
            s1 = s1 + s2;
            std::cout << s1 << '\n';
        }
        else if (num == 2)
        {
            int a, b;
            std::cin >> a >> b;
            std::string s2 = s1.substr(a, b);
            s1 = s2;
            std::cout << s1 << '\n';
        }
        else if (num == 3)
        {
            int a;
            std::string s2;
            std::cin >> a >> s2;
            s1.insert(a, s2);
            std::cout << s1 << '\n';
        }
        else if (num == 4)
        {
            std::string s2;
            std::cin >> s2;
            if (s1.find(s2) == std::string::npos)
            {
                std::cout << -1 << '\n';
            }
            else
                std::cout << s1.find(s2) << '\n';
        }
    }
    return 0;
}
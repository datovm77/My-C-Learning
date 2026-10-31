#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string s;
    std::string t;
    if (!(std::cin >> s >> t))
        return 0;

    int slow = 0;
    int fast = 0;

    int count = 0;
    for (int i = 0; i < static_cast<int>(s.size()); i++)
    {
        if (slow == static_cast<int>(t.size()))
            break; // t 已经全部匹配

        if (s[fast] == t[slow])
        {
            fast++;
            slow++;
            count++;
        }
        else
        {
            fast++;
        }
    }

    std::cout << count << '\n';
}

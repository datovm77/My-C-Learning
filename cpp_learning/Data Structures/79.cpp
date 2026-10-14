#include <iostream>
#include <map>

int main()
{
    std::ios::sync_with_stdio(0);
    int t;
    std::cin >> t;
    std::map<std::string, int> m;
    while (t--)
    {
        int cal;
        std::cin >> cal;
        if (cal == 1)
        {
            std::string name;
            int score;
            std::cin >> name >> score;
            m[name] = score;
            std::cout << "OK" << '\n';
        }
        else if (cal == 2)
        {
            std::string name;
            std::cin >> name;
            if (m.find(name) != m.end())
            {
                std::cout << m[name] << '\n';
            }
            else
            {
                std::cout << "Not found" << '\n';
            }
        }
        else if (cal == 3)
        {
            std::string name;
            std::cin >> name;
            if (m.erase(name))
            {
                std::cout << "Deleted successfully" << '\n';
            }
            else
            {
                std::cout << "Not found" << '\n';
            }
        }
        else if (cal == 4)
        {
            std::cout << m.size() << '\n';
        }
    }
    return 0;
}
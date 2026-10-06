#include <iostream>
#include <set>

int main()
{
    int t;
    std::cin >> t;
    std::set<int> s1;
    for (int i = 0; i < t; i++)
    {
        int number;
        std::cin >> number;
        s1.insert(number);
    }

    std::cout << s1.size() << '\n';
    bool first = true;
    for (int x : s1)
    {
        if (!first)
            std::cout << " ";

        std::cout << x;
        first = false;
    }
    std::cout << '\n';
    return 0;
}
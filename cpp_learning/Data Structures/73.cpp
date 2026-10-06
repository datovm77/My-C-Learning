#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
    int t;
    std::cin >> t;
    std::vector<int> v1;
    for (int i = 0; i < t; i++)
    {
        int number;
        std::cin >> number;
        v1.push_back(number);
    }
    std::sort(v1.begin(), v1.end());
    for (int i = 0; i < t; i++)
    {
        if (i != 0)
        {
            std::cout << ' ';
        }
        std::cout << v1[i];
    }
    std::cout << '\n';
    return 0;
}
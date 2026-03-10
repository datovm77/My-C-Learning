#include <iostream>
#include <unordered_map>
#include <string>
//P1918 保龄球  
void test01()
{
    int n;
    std::cin >> n;
    std::unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int temp;
        std::cin >> temp;
        m.emplace(temp, i + 1);
    }
    int times;
    std::cin >> times;
    for (int i = 0; i < times; ++i)
    {
        int temp1;
        std::cin >> temp1;
        if (m.find(temp1) != m.end())
            std::cout << m.at(temp1) << '\n';
        else std::cout<<'0'<<'\n';
    }
}

int main()
{
    test01();
    return 0;
}
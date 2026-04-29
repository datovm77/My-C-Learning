// 练习用unordered_map实现保龄球得分快速查找
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
        auto it = m.find(temp1);
        if (it != m.end())
            std::cout << it->second << '\n';
        else
            std::cout << '0' << '\n';

    }
}

int main()
{
    test01();
    return 0;
}
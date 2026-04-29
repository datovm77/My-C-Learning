// 练习用find_if和lambda表达式查找满足条件的元素
#include <iostream>
#include <algorithm>
#include <vector>

bool isEven(int n1)
{
    if (n1 % 2 == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void test01()
{
    std::vector<int> v1 = {1, 2, 3, 5, 7, 9};
    auto it = std::find_if(v1.begin(), v1.end(), [](int val)
                           { return val % 2 == 0; });

    if (it != v1.end())
        std::cout << "已找到第一个偶数" << *it << '\n';
    else
        std::cout << "没用找到" << '\n';
}

int main()
{
    test01();

    return 0;
}
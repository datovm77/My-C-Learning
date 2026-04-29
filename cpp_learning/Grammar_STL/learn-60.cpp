// 练习猫类按体重排序，std::sort配合lambda比较器
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
class cat
{
public:
    std::string name;
    int weight;
};

void test01()
{
    int n;
    std::cin >> n;
    std::vector<cat> vec(n);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> vec[i].name >> vec[i].weight;
    }
    std::sort(vec.begin(), vec.end(), [](const cat &c1, const cat &c2)
              { return c1.weight < c2.weight; });

    for (int i = 0; i < n; ++i)
    {
        if (i == 0)
        {
            std::cout << vec[i].name;
        }
        else
        {
            std::cout << " " << vec[i].name;
        }
    }
    std::cout << '\n';
}

int main()
{
    test01();
    return 0;
}

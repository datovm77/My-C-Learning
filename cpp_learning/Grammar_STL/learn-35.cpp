// 练习set容器基本用法与自定义比较器降序排序
#include <iostream>
#include <set>
#include <string>
// set
class mycompare
{
public:
    bool operator()(const int &v1, const int &v2) const
    {
        return v1 > v2;
    }
};

void test01()
{
    std::set<int> s1;
    s1.insert(10);
    s1.insert(30);
    s1.insert(20);
    s1.insert(50);

    for (int n : s1)
    {
        std::cout << n << ' ';
    }
    std::cout << '\n';

    std::set<int, mycompare> s2;
    s2.insert(10);
    s2.insert(30);
    s2.insert(20);
    s2.insert(50);

    for (int n : s2)
    {
        std::cout << n << ' ';
    }
    std::cout << '\n';

    std::set<int, std::greater<int>> s3;
    s3.insert(10);
    s3.insert(30);
    s3.insert(20);
    s3.insert(50);
    for (int n : s3)
    {
        std::cout << n << ' ';
    }
    std::cout << '\n';
}

int main()
{
    test01();

    return 0;
}
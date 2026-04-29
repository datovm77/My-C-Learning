// 练习vector容器基础操作与模板打印函数，知识点：vector增删、模板函数、范围for
#include <iostream>
#include <string>
#include <vector>

template <class T>
void Print_vector(const std::vector<T>& v)
{
    // for(auto it = v.begin();it!=v.end();++it)
    // {
    //     std::cout<<*it <<" ";
    // }
    // std::cout<<"\n";

    for (const T& num : v)
    {
        std::cout << num << " ";
    }
    std::cout << "\n";
}

void test01()
{
    std::vector<int> v;
    for (int i = 0; i < 10; ++i)
    {
        v.push_back(i * 10);
    }

    Print_vector(v);

    // 通过区间构造
    std::vector<int> v2(v.begin(), v.end());
    Print_vector(v2);

    // n个元素的构造
    std::vector<std::string> v3(10, "gem");
    Print_vector(v3);

    // 拷贝构造
    std::vector<int> v4(v);
    Print_vector(v4);
}

int main()
{
    test01();

    return 0;
}

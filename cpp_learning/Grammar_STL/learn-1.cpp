#include <iostream>
#include <vector>
#include <algorithm>

void MyPrint(int val)
{
    std::cout << val <<std::endl;
}

void test01()
{
    std::vector<int> v;

    // 插入数据
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);

    // std::vector<int>::iterator itBegin = v.begin();//起始迭代器 指向第一个元素
    // std::vector<int>::iterator itEnd = v.end(); //结束迭代器，指向最后一个元素的下一个位置

    // while(itBegin!=itEnd)
    // {
    //     std::cout << *itBegin << std::endl;
    //     itBegin++;
    // }

    for (std::vector<int>::iterator it = v.begin(); it != v.end(); it++)
    {
        std::cout << *it << std::endl;
    }


    // // 使用 auto 关键字自动推导迭代器类型
    // for (auto it = v.begin(); it != v.end(); it++)
    // {
    //     std::cout << *it << std::endl;
    // }

    
    //基于范围的 for 循环
    for (const int &val : v) 
    {
        std::cout << val << " ";
    }

    //std::for_each(v.begin(),v.end(),MyPrint);
}

void test02()
{
    std::vector<int> v = {10, 20, 30, 40, 50};

    std::cout << "使用 Lambda 和 std::for_each 遍历：" << std::endl;
    std::for_each(v.begin(), v.end(), [](int val) {
        std::cout << val << " ";
    });
    std::cout << std::endl;

    int sum = 0;
    std::for_each(v.begin(), v.end(), [&sum](int val) {
        sum += val;
    });
    std::cout << "总和为：" << sum << std::endl;
}


int main()
{

    test01();

    // std::cout << "\n--- Lambda 方式 ---" << std::endl;
    // test02();

    return 0;
}
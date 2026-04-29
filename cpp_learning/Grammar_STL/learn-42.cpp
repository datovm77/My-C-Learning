// 练习用set管理木材仓库有序集合的插入与查找
#include <iostream>
#include <set>
// /P5250 【深基17.例5】木材仓库
void test01()
{
    int times;
    std::cin >> times;

    std::set<int> wood_length;

    for (int i = 0; i < times; ++i)
    {
        int in_or_out;
        int length;
        std::cin >> in_or_out >> length;
        if (in_or_out == 1)
        {
            auto result = wood_length.insert(length);
            if (!result.second)
            {
                std::cout << "Already Exist" << '\n';
            }
        }
        else
        {
            if (wood_length.empty())
            {
                std::cout << "Empty" << '\n';
            }
            else
            {
                auto it = wood_length.find(length);
                if (it != wood_length.end())
                {
                    std::cout << *it << '\n';
                    wood_length.erase(*it);
                }
                else
                {
                    auto it = wood_length.lower_bound(length);
                    int final_result;
                    if (it == wood_length.end())
                    {
                        // 所有元素都 < length，取最大的
                        final_result = *std::prev(it);
                    }
                    else if (it == wood_length.begin())
                    {
                        // 所有元素都 > length，取最小的
                        final_result = *it;
                    }
                    else
                    {
                        // 两侧都有候选，比较差值
                        int right = *it;
                        int left = *std::prev(it);
                        // 差值相等时取较短的（left）
                        final_result = (right - length) >= (length - left) ? left : right;
                    }
                    std::cout << final_result << '\n';
                    wood_length.erase(final_result);
                }
            }
        }
    }
}

int main()
{
    test01();
    return 0;
}
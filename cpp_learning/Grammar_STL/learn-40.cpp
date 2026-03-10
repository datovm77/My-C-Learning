#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
// 1. 两数之和（不熟练）
class Solution
{
public:
    std::vector<int> twoSum(std::vector<int> &nums, int target)
    {
        std::unordered_map<int, int> m;

        for (int i = 0; i < static_cast<int>(nums.size()); ++i)
        {
            auto it = m.find(target - nums[i]);
            if (it != m.end())
            {
                return {it->second, i};
            }
            m.emplace(nums[i], i);
        }
        return {};
    }
};
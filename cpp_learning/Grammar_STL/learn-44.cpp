// 练习用哈希表实现字母异位词分组LeetCode 49
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <algorithm>

class Solution
{
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string> &strs)
    {
        std::unordered_map<std::string, std::vector<std::string>> news;

        for (size_t i = 0; i < strs.size(); ++i)
        {
            std::string temp = strs[i];

            std::sort(temp.begin(), temp.end());

            news[temp].emplace_back(strs[i]);
        }

        std::vector<std::vector<std::string>> result;
        for (const auto &it : news)
        {
            result.emplace_back(it.second);
        }
        return result;
    }
};
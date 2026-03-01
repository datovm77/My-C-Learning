#include<iostream>
#include<string>
#include<vector>
#include <algorithm> // 引入 sort
//力扣 14. 最长公共前缀 解法3

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) 
    {
        if (strs.empty()) return "";

        // 按字典序从小到大排序
        std::sort(strs.begin(), strs.end());

        // 拿字典序最小（最前）和最大（最后）的两个字符串进行对比即可
        const std::string& first = strs.front();
        const std::string& last = strs.back();
        
        int i = 0;
        int min_len = std::min(first.size(), last.size());
        while (i < min_len && first[i] == last[i]) {
            ++i;
        }
        
        return first.substr(0, i);
    }
};
void test01()
{
    std::vector<std::string> strs {"flower","flow","flight"};
    Solution s1;
    std::string str = s1.longestCommonPrefix(strs);
    std::cout << str <<std::endl;
}

int main()
{
    test01();

    return 0;
}
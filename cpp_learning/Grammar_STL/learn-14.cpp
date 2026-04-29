// 练习LeetCode 14 最长公共前缀（优化竖向扫描），知识点：逐列比较、提前返回
#include<iostream>
#include<string>
#include<vector>
//力扣 14. 最长公共前缀 解法一

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (strs.empty()) return "";

        // 以第一个字符串为基准
        for (int i = 0; i < strs[0].size(); ++i) {
            char c = strs[0][i];
            // 扫描其他所有字符串的第 i 位字符
            for (int j = 1; j < strs.size(); ++j) {
                // 如果其他字符串已经遍历完，或者字符不一致，就可以返回了
                if (i == strs[j].size() || strs[j][i] != c) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0]; // 如果顺利遍历完，说明第一个字符串本身就是最长公共前缀
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

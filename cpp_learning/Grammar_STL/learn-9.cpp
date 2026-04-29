// 练习LeetCode 58 最后一个单词长度（类解法），知识点：反向遍历、字符串下标
#include<iostream>
#include<string>

class Solution {
public:
    int lengthOfLastWord(std::string s)
    {
        int length = 0;
        int sum = s.size();
        while(sum >=0 && s[sum] == ' ')
        {
            sum--;
        }
        while(sum >= 0&& s[sum] != ' ')
        {
            length++;
            sum--;
        }
        return length;

    }
};

int main()
{
    Solution s1;
    s1.lengthOfLastWord("   fly me   to   the moon  ");

    return 0;
}

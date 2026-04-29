// 练习LeetCode 151 反转字符串中的单词（方法一），知识点：去空格、反转、单词分割
#include <iostream>
#include <string>
#include <algorithm>
// 151. 反转字符串中的单词
class Solution
{
public:
    std::string reverseWords(std::string s)
    {
        size_t length = s.size();
        if (length == 0)
            return "";

        size_t begin = 0;
        size_t end = s.size() - 1;

        while (end > 0 && s[end] == ' ')
        {
            end--;
        }
        while (begin < end && s[begin] == ' ')
        {
            begin++;
        }

        std::string s1 = s.substr(begin, end - begin + 1); // 第二个参数是"长度"
        //std::cout << s1 << std::endl;
        std::string str_result = "";

        int end1 = static_cast<int>(s1.size()) - 1;
        while (end1 >= 0)
        {
            int right = end1;
            while (end1 >= 0 && s1[end1] != ' ')
            {
                end1--;
            }
            str_result += s1.substr(end1 + 1, right - end1) + " ";
            while (end1 >= 0 && s1[end1] == ' ')
            {
                end1--;
            }
        }
        if (!str_result.empty())
        {
            str_result.pop_back();
        }
        //std::cout << str_result << std::endl;
        return str_result;
    }
};

void test01()
{
    std::string str = "  a good   example  ";
    Solution s1;
    s1.reverseWords(str);
}

int main()
{
    test01();

    return 0;
}



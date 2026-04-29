// 练习LeetCode 151 反转字符串中的单词（原地解法），知识点：快慢指针、原地修改、reverse
#include <iostream>
#include <string>
#include <algorithm>
// 151. 反转字符串中的单词
class Solution {
public:
    std::string reverseWords(std::string s) {
        // 第1步：原地去除多余空格（快慢指针）、
        //std::string str = "  a good   example  ";
        int slow = 0;
        int n = static_cast<int>(s.size());
        for (int fast = 0; fast < n; ++fast) {
            if (s[fast] != ' ') {
                // 在单词之间加一个空格
                if (slow != 0) {
                    s[slow++] = ' ';
                }
                // 拷贝整个单词
                while (fast < n && s[fast] != ' ') {
                    s[slow++] = s[fast++];
                }
            }
        }
        s.resize(slow);  // 截断多余部分

        // 第2步：整体反转
        std::reverse(s.begin(), s.end());

        // 第3步：逐个单词内部反转
        int start = 0;
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') {
                std::reverse(s.begin() + start, s.begin() + i);
                start = i + 1;
            }
        }

        return s;
    }
};

void test01()
{
    std::string str = "  a good   example  ";
    Solution s1;
    std::cout << s1.reverseWords(str) << std::endl;
}

int main()
{
    test01();

    return 0;
}

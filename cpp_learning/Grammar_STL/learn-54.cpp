// 练习罗马数字转整数，switch-case替代哈希表的优化方案
#include <iostream>
#include <string>

class Solution
{
private:
    // 取消哈希表查字符串，改成最原始的 O(1) 多分支判断映射
    // switch-case 语句在底层会被编译器优化为跳跃表非常快
    int getValue(char ch)
    {
        switch (ch)
        {
        case 'I':
            return 1;
        case 'V':
            return 5;
        case 'X':
            return 10;
        case 'L':
            return 50;
        case 'C':
            return 100;
        case 'D':
            return 500;
        case 'M':
            return 1000;
        default:
            return 0;
        }
    }

public:
    int romanToInt(const std::string &s)
    {
        int sum = 0;
        int n = s.length();

        for (int i = 0; i < n; ++i)
        {
            int currentValue = getValue(s[i]);

            // 如果还不是最后一个字符，且当前字符对应的数值比右边字符的小
            if (i < n - 1 && currentValue < getValue(s[i + 1]))
            {
                sum -= currentValue;
            }
            else
            {
                // 其他所有情况（左边比右边大、或者左右两边一样大、或者是最后一个字符）
                sum += currentValue;
            }
        }

        return sum;
    }
};

#include <iostream>
#include <string>
#include <unordered_map>

class Solution {
public:
    int romanToInt(const std::string &s) {
        // 【优化1】：加上 static 关键字。
        // 这样这个哈希表在整个程序运行期间只会初始化一次，避免每次调用函数时分配内存和构建表。
        static const std::unordered_map<std::string, int> mp = {
            {"IV", 4}, {"IX", 9}, {"XL", 40}, {"XC", 90}, {"CD", 400}, {"CM", 900},
            {"I", 1}, {"V", 5}, {"X", 10}, {"L", 50}, {"C", 100}, {"D", 500}, {"M", 1000}
        };

        int sum = 0;
        size_t len = s.size();

        // 【优化4】：去掉了无用的 if(temp.size() == 0) 判断，直接开始遍历
        for (int i = 0; i < len; ++i) {
            // 先尝试向后看一位：取2个字符
            if (i < len - 1) {
                // 【优化2】：直接用 substr 截取连续 2 个字符，代替反复执行 += 的字符串拼接操作
                std::string temp_t = s.substr(i, 2);
                
                auto it = mp.find(temp_t);
                if (it != mp.end()) {
                    // 【优化3】：直接通过迭代器 it->second 获取值，避免使用 mp[temp_t] 造成底层的二次哈希计算和查找
                    sum += it->second; 
                    ++i; // 我们一次性消耗了 2 个字符，所以手动把指针往后多挪一个位置
                    continue; // 匹配成功，直接进入下一轮循环
                }
            }

            // 如果没能进入上面的 if 或匹配失败，说明当前只是 1 个独立的单字符
            std::string temp = s.substr(i, 1);
            auto it = mp.find(temp);
            if (it != mp.end()) {
                sum += it->second;
            }
        }
        
        return sum;
    }
};

// P1100 高低位交换
#include <iostream>
#include <string>
#include <algorithm>
int main()
{
    long long number;
    std::cin >> number;
    std::string s1 = "";

    // 10进制转二进制
    while (number != 0)
    {
        long long res = number % 2;
        char c_res = res + '0';
        s1.push_back(c_res);
        number /= 2;
    }
    std::reverse(s1.begin(), s1.end());

    int len = static_cast<int>(s1.size());
    int res = 32 - len;
    std::string s2;
    s2.assign(res, '0');
    s2 += s1;
    len = static_cast<int>(s2.size());
    int middle = 16;

    std::string pre = s2.substr(0, middle);
    std::string post = s2.substr(middle, len);

    std::string result = post + pre;

    // 二进制转化为10进制
    long long num = 0;
    int index = 0; // 原代码从末尾向前计算，导致二进制位序被反着解释。
    while (index < len)
    {
        num = num * 2 + static_cast<int>(result[index] - '0');
        index++;
    }
    std::cout << num << '\n';
    return 0;
}

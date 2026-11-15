// P1143 进制转换
#include <iostream>
#include <string>
#include <algorithm>
const char s[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

int chartodigit(char c)
{
    if (c >= '0' && c <= '9') // 原代码写成 c <= 9，字符与整数比较导致数字无法识别。
        return c - '0';
    if (c >= 'A' && c <= 'Z')
        return c - 'A' + 10;
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 10;
    return -1; // 原代码对非法字符返回 0，会把非法输入当成数字 0。
}

// 任意进制转化为十进制
long long toDecimal(std::string s1, int pre)
{
    if (pre < 2 || pre > 16) // 原代码只检查目标进制，没有检查源进制。
        return -1;

    long long ans = 0; // 原代码未初始化 ans，直接参与运算会产生未定义行为。
    for (char c : s1)
    {
        int digit = chartodigit(c);
        if (digit < 0 || digit >= pre) // 原代码没有检查字符是否属于当前进制。
            return -1;

        ans = ans * pre + digit;
    }
    return ans;
}

// 十进制转化为任意进制
std::string fromDecimal(long long n, int base)
{
    if (base < 2 || base > 16 || n < 0)
    {
        return "";
    }
    if (n == 0)
        return "0";

    std::string ans = "";

    while (n > 0)
    {
        int remainder = n % base;
        ans += s[remainder];
        n /= base;
    }

    std::reverse(ans.begin(), ans.end());

    return ans;
}
std::string convertBase(std::string num,
                        int fromBase,
                        int toBase)
{
    long long decimal = toDecimal(num, fromBase);

    return fromDecimal(decimal, toBase);
}
int main()
{
    std::ios::sync_with_stdio(0);

    int pre_n;
    std::string number;
    int post_n;

    std::cin >> pre_n >> number >> post_n;
    std::string result = convertBase(number, pre_n, post_n);

    std::cout << result << '\n';
}

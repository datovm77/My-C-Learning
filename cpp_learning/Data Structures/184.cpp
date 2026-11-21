// CSP202605A 银行家舍入
#include <iostream>
#include <string>
#include <vector>

int main()
{
    int n;
    if (!(std::cin >> n))
        return 0;

    std::vector<int> normal_results(n); // 四舍五入的结果
    std::vector<int> banker_results(n); // 银行家舍入的结果

    for (int i = 0; i < n; i++)
    {
        std::string number;
        std::cin >> number;

        // 例如 "2026.5"：小数点前是 2026，小数点后是 5。
        std::size_t dot = number.find('.');
        int integer_part = std::stoi(number.substr(0, dot));
        int decimal_digit = number[dot + 1] - '0'; // 字符 '5' 转为数字 5

        // 四舍五入：小数位为 5～9 时进一，否则保留整数部分。
        normal_results[i] = integer_part;
        if (decimal_digit >= 5)
            normal_results[i]++;

        banker_results[i] = integer_part;
        if (decimal_digit > 5)
        {
            // 小数位为 6～9，直接进一。
            banker_results[i]++;
        }
        else if (decimal_digit == 5 && integer_part % 2 != 0)
        {
            // 小数位为 5：整数部分是奇数时进一，变成偶数。
            banker_results[i]++;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (i > 0)
            std::cout << ' ';
        std::cout << normal_results[i];
    }
    std::cout << '\n';

    for (int i = 0; i < n; i++)
    {
        if (i > 0)
            std::cout << ' ';
        std::cout << banker_results[i];
    }
    std::cout << '\n';
}

// P1469 找筷子
#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    int result = 0; // 0 是异或的初始值：x ^ 0 == x。
    for (int i = 0; i < n; ++i)
    {
        int number;
        std::cin >> number;
        result ^= number;
    }

    std::cout << result << '\n';
}

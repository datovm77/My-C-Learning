// P1100 高低位交换
#include <cstdint>
#include <iostream>

int main()
{
    std::uint32_t number;
    std::cin >> number;

    // 左移 16 位交换到低半部分，右移 16 位交换到高半部分。
    const std::uint32_t result = (number << 16) | (number >> 16);

    std::cout << result << '\n';
    return 0;
}

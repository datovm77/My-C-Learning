#include <iostream>

// 判断一个数是否为质数。
bool isPrime(int number)
{
    // 质数必须大于 1。
    if (number < 2)
        return false;

    // 如果 number 有一个大于 sqrt(number) 的因数，
    // 那么它一定也有一个更小的因数，所以只需检查到 i * i <= number。
    for (int i = 2; i * i <= number; i++)
    {
        if (number % i == 0)
            return false;
    }

    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    if (!(std::cin >> n))
        return 0;

    int numbers[100];

    // 先把输入的所有整数保存到数组中。
    for (int i = 0; i < n; i++)
        std::cin >> numbers[i];

    // 依次判断并输出数组中的质数。
    bool first = true;
    for (int i = 0; i < n; i++)
    {
        if (isPrime(numbers[i]))
        {
            if (!first)
                std::cout << ' ';

            std::cout << numbers[i];
            first = false;
        }
    }

    std::cout << '\n';
    return 0;
}

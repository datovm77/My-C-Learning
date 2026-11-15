// P5723 【深基4.例13】质数口袋
#include <iostream>

// 判断 number 是否为质数。
bool isPrime(int number)
{
    if (number < 2)
        return false;

    // 只需检查到平方根：如果存在更大的因数，就一定也有一个更小的因数。
    for (int divisor = 2; divisor * divisor <= number; divisor++)
    {
        if (number % divisor == 0)
            return false;
    }

    return true;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int limit;
    std::cin >> limit;

    int totalWeight = 0; // 口袋里质数的总和
    int primeCount = 0;  // 口袋里质数的个数

    // 从 2 开始依次检查每个自然数。
    for (int candidate = 2; candidate <= limit; candidate++)
    {
        if (!isPrime(candidate))
            continue;

        // 下一个质数放不进去时，后面的质数更大，也都放不进去。
        if (totalWeight + candidate > limit)
            break;

        std::cout << candidate << '\n';
        totalWeight += candidate;
        primeCount++;
    }

    std::cout << primeCount << '\n';
    return 0;
}

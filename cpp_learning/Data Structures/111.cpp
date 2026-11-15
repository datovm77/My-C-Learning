// P5723 【深基4.例13】质数口袋
#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    std::vector<int> primes;
    std::vector<bool> iscomposite(n + 1, false);
    for (int i = 2; i <= n; i++)
    {
        if (!iscomposite[i])
            primes.push_back(i);

        for (int p : primes)
        {
            if (1LL * i * p > n)
                break;
            iscomposite[i * p] = true;
            if (i % p == 0)
                break;
        }
    }

    int len = static_cast<int>(primes.size());
    std::vector<int> sum_primes(len + 1, 0);

    int index = 0;
    for (int i = 1; i <= len; i++)
    {
        sum_primes[i] = sum_primes[i - 1] + primes[i - 1];
        if (sum_primes[i] > n)
        {
            index = i - 1;
            break;
        }
        else if (sum_primes[i] == n)
        {
            index = i;
            break;
        }
    }
    for (int i = 0; i < index; i++)
    {
        std::cout << primes[i] << '\n';
    }
    std::cout << index << '\n';
    return 0;
}
#include <iostream>
#include <vector>
#include <algorithm>
int main()
{
    int n;
    if (!(std::cin >> n))
        return 0;
    std::vector<int> numbers;
    for (int i = 0; i < n; i++)
    {
        int num;
        std::cin >> num;
        numbers.push_back(num);
    }

    std::vector<int> primes;
    int max_size = 100000;
    std::vector<bool> iscomposite(max_size + 1, false);
    for (int i = 2; i <= max_size; i++)
    {
        if (!iscomposite[i])
            primes.push_back(i);
        for (int p : primes)
        {
            if (1LL * i * p > max_size)
                break;
            iscomposite[i * p] = true;
            if (i % p == 0)
                break;
        }
    }
    int head = 1;
    for (int x : numbers)
    {
        if (std::count(primes.begin(), primes.end(), x) == 1)
        {
            if (head)
            {
                std::cout << x;
                head = 0;
            }
            else
            {
                std::cout << ' ' << x;
            }
        }
    }
    std::cout << '\n';
}
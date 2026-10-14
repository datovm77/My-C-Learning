#include <iostream>
#include <vector>
int main()
{
    std::ios::sync_with_stdio(0);
    int n;
    std::cin >> n;
    std::vector<int> numbers(n);

    for (int i = 0; i < n; i++)
    {
        int number;
        std::cin >> number;

        numbers[i] = number;
    }

    long long sum = 0;
    long long pre = 0;
    for (int x : numbers)
    {
        sum += pre * x;
        pre += x;
    }

    std::cout << sum << '\n';
    return 0;
}
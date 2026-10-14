#include <iostream>
#include <vector>
int main()
{
    std::ios::sync_with_stdio(0);
    int n;
    std::vector<int> v1;
    std::cin >> n;
    for (int i = 0; i < n; i++)
    {
        int number;
        std::cin >> number;
        v1.push_back(number);
    }
    std::vector<long long> sum(n + 1, 0);
    sum[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        sum[i] = sum[i - 1] + v1[i - 1];
    }
    int m;
    std::cin >> m;
    while (m--)
    {
        int l, r;
        std::cin >> l >> r;
        long long result = sum[r] - sum[l - 1];
        std::cout << result << '\n';
    }
    return 0;
}
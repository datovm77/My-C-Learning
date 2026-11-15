// P8680 [蓝桥杯 2019 省 B] 特别数的和
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n;
    if (!(std::cin >> n))
        return 0;

    long long sum = 0;
    std::vector<int> v = {2, 0, 1, 9};
    for (int i = 1; i <= n; i++)
    {
        int x = i;
        while (x != 0)
        {
            int z = x % 10;
            if (std::find(v.begin(), v.end(), z) != v.end())
            {
                sum += i;
                break;
            }
            x /= 10;
        }
    }

    std::cout << sum << '\n';
}
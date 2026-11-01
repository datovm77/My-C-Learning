// P1873 [COCI 2011/2012 #5] EKO / 砍树
#include <iostream>
#include <algorithm>
#include <vector>

bool check(const std::vector<int> &a, int len, int high)
{
    long long sum = 0;
    for (const int &x : a)
    {
        sum += std::max(0, x - high);
        if (sum >= len)
            return true;
    }

    return false;
}

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(nullptr);
    int N, M;
    std::cin >> N >> M;
    std::vector<int> high;

    int max_len = 0;
    for (int i = 0; i < N; i++)
    {
        int number;
        std::cin >> number;
        max_len = std::max(number, max_len);
        high.push_back(number);
    }

    int l = 1;
    int r = max_len;

    int ans = 0;
    while (l <= r)
    {
        long long mid = l + (r - l) / 2;

        if (check(high, M, mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    std::cout << ans << '\n';
}

// P8647 [蓝桥杯 2017 省 AB] 分巧克力
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <utility>

bool check(const std::vector<std::pair<int, int>> &sq, int len, int K) // 原：bool check(const std::vector<std::pair<int, int>> sq, int len, int K)
{
    long long sum = 0;
    for (const auto &[h, w] : sq) // 原：for (auto &[h, w] : sq)
    {
        int x = h / len;
        int y = w / len;

        sum += 1LL * x * y; // 原：sum += (x * y);
        if (sum >= K)
            return true;
    }
    return false;
}

int main()
{
    int N, K;
    if (!(std::cin >> N >> K))
        return 0;
    std::vector<std::pair<int, int>> sq;

    int max = 0;
    for (int i = 0; i < N; i++)
    {
        int H, W;
        std::cin >> H >> W;
        max = std::max(max, std::max(H, W));
        sq.push_back(std::make_pair(H, W));
    }

    int l = 1;
    int r = max;

    long long ans = 0;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (check(sq, mid, K))
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

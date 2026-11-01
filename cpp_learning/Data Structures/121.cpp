// P1918 保龄球
#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(nullptr);

    int n;
    if (!(std::cin >> n))
        return 0;

    std::vector<std::pair<int, int>> a(n);

    for (int i = 1; i <= n; i++)
    {
        int number;
        std::cin >> number;
        a[i - 1] = {number, i};
    }

    std::sort(a.begin(), a.end());

    int Q;
    std::cin >> Q;
    while (Q--)
    {
        int m;
        std::cin >> m;

        int l = 0, r = n - 1;
        int ans = 0;

        while (l <= r)
        {
            int mid = l + (r - l) / 2;
            if (a[mid].first == m)
            {
                ans = a[mid].second;
                break;
            }
            else if (a[mid].first < m)
            {
                l = mid + 1;
            }
            else
                r = mid - 1;
        }
        std::cout << ans << '\n';
    }
    return 0;
}

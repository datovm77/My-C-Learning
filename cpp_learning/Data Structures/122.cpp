// P1678 烦恼的高考志愿
#include <iostream>
#include <algorithm>
#include <vector>
#include <climits>
int lowerbound(const std::vector<int> sch, int x)
{
}

int main()
{
    std::ios::sync_with_stdio(0);
    int m, n;
    if (!(std::cin >> m >> n))
        return 0;
    std::vector<int> school(m);

    for (int i = 0; i < m; i++)
    {
        std::cin >> school[i];
    }
    std::sort(school.begin(), school.end());

    long long ans = 0;
    while (n--)
    {
        int b;
        std::cin >> b;

        int l = 0;
        int r = m - 1;
        int pos = m;
        while (l <= r)
        {
            int mid = l + (r - l) / 2;

            if (school[mid] >= b)
            {
                pos = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }

        int minn = INT_MAX;

        if (pos < m)
        {
            minn = std::min(minn, abs(school[pos] - b));
        }
        if (pos > 0)
        {
            minn = std::min(minn, abs(school[pos - 1] - b));
        }
        ans += minn;
    }
    std::cout << ans << '\n';

    return 0;
}

// P1638 逛画展
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int n, m;
    std::cin >> n >> m;

    std::vector<int> a(n + 1);
    std::vector<int> cnt(m + 1, 0);

    for (int i = 1; i <= n; i++)
    {
        std::cin >> a[i];
    }

    int l = 1;
    int kind = 0;

    int ansL = 1, ansR = n;
    int minLen = n + 1;

    for (int r = 1; r <= n; r++)
    {
        cnt[a[r]]++;
        if (cnt[a[r]] == 1)
            kind++;
        while (kind == m)
        {
            int len = r - l + 1;
            if (len < minLen)
            {
                minLen = len;
                ansL = l;
                ansR = r;
            }

            cnt[a[l]]--;
            if (cnt[a[l]] == 0)
                kind--;
            l++;
        }
    }
    std::cout << ansL << " " << ansR << '\n';

    return 0;
}

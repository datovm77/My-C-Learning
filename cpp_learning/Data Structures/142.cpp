#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    int w;
    int n;
    if (!(std::cin >> w >> n))
        return 0;
    std::vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> v[i];
    }
    std::sort(v.begin(), v.end());

    int ans = 0;
    int l = 0;
    int r = n - 1;

    while (l <= r)
    {
        if (v[r] + v[l] <= w && l < r)
        {
            l++;
        }
        r--;
        ans++;
    }
    std::cout << ans << '\n';
}
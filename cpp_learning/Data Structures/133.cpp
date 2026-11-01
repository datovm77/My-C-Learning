// P3853 [TJOI2007] 路标设置
#include <iostream>
#include <vector>
#include <algorithm>

bool check(const std::vector<int> &v, int len, int k)
{
    long long total = 0;

    for (int i = 1; i < static_cast<int>(v.size()); i++)
    {
        int gap = v[i] - v[i - 1];
        total += (gap - 1) / len;

        if (total > k)
            return false;
    }

    return true;
}

int main()
{
    int L, K, N;
    if (!(std::cin >> L >> N >> K))
        return 0;
    std::vector<int> lens(N, 0);

    for (int i = 0; i < N; i++)
    {
        std::cin >> lens[i];
    }
    int l = 1;
    int r = *std::max_element(lens.begin(), lens.end());

    int ans = 0;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (check(lens, mid, K))
        {
            r = mid - 1;
            ans = mid;
        }
        else
            l = mid + 1;
    }
    std::cout << ans << '\n';
}

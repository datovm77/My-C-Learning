#include <iostream>
#include <vector>

bool check(const std::vector<int> &v, long long l, int k) // 原：bool check(const std::vector<int> &v, int l, int k)
{
    long long sum = 0; // 原：int sum = 0;
    for (const int &x : v)
    {
        sum += (x / l);
        if (sum >= k)
            return true;
    }
    return false;
}

int main()
{
    int n, k;
    if (!(std::cin >> n >> k))
        return 0;
    std::vector<int> lens;

    int max = 0;
    for (int i = 0; i < n; i++)
    {
        int len;
        std::cin >> len;
        if (len > max)
            max = len;
        lens.push_back(len);
    }

    long long l = 1;   // 原：int l = 1;
    long long r = max; // 原：int r = max;

    long long ans = 0;
    while (l <= r)
    {
        long long mid = l + (r - l) / 2; // 原：int mid = l + (r - l) / 2;

        if (check(lens, mid, k))
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid - 1;
    }
    std::cout << ans << '\n';
}

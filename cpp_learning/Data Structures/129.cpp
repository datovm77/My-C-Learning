#include <iostream>
#include <vector>
#include <algorithm>

int lower_bound(const std::vector<long long> &a, long long t) // 原：int lower_bound(std::vector<int> &a, int t)
{
    int l = 0, r = static_cast<int>(a.size()) - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (a[mid] < t)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l;
}

int upper_bound_(const std::vector<long long> &a, long long t) // 原：int upper_bound_(std::vector<int> &a, int t)
{
    int l = 0, r = (int)a.size() - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (a[mid] <= t)
            l = mid + 1;
        else
            r = mid - 1;
    }
    return l;
}

int main()
{
    int N;
    long long C;
    if (!(std::cin >> N >> C))
        return 0;
    std::vector<long long> v(N);
    for (int i = 0; i < N; i++)
    {
        std::cin >> v[i];
    }
    std::sort(v.begin(), v.end());

    long long count = 0;

    for (int i = 0; i < N; i++)
    {
        long long target = v[i] - C;

        int left = lower_bound(v, target);   // 原：auto left = std::lower_bound(v.begin(), v.end(), target);
        int right = upper_bound_(v, target); // 原：auto right = std::upper_bound(v.begin(), v.end(), target);

        count += right - left;
    }
    std::cout << count << '\n';
}

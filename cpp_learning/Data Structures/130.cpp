#include <iostream>
#include <vector>
#include <algorithm>

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

    int left = 0;
    int right = 0;
    long long count = 0;

    for (int i = 0; i < N; i++)
    {
        long long target = v[i] - C;

        // 找到第一个不小于 target 的位置。
        while (left < N && v[left] < target)
            left++;

        // 找到第一个大于 target 的位置。
        while (right < N && v[right] <= target)
            right++;

        // [left, right) 中都是能与 v[i] 配对的数。
        count += right - left;
    }

    std::cout << count << '\n';
}

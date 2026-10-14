#include <iostream>
#include <vector>
int main()
{
    std::ios::sync_with_stdio(0);
    int n, m;
    std::cin >> n >> m;

    // sum[i] 表示前 i 个刺痛值的和。
    std::vector<long long> sum(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        int number;
        std::cin >> number;
        sum[i + 1] = sum[i] + number;
    }
    // 第一段长度为 m 的连续区间作为初始最小值；m 为 0 时结果也是 0。
    long long min_sum = sum[m];
    for (int i = 0; i <= n - m; i++)
    {
        // 区间 [i, i + m) 的和。
        long long window_sum = sum[i + m] - sum[i];
        if (window_sum < min_sum)
            min_sum = window_sum;
    }
    std::cout << min_sum << '\n';
}

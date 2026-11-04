#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(nullptr);
    long long a, b, n;
    if (!(std::cin >> a >> b >> n))
        return 0;

    long long one_week_learn = 5 * a + 2 * b;

    long long sum_days = (n / one_week_learn) * 7;

    // 剩下的题一周内可以完成
    long long sum_days_rest = n % one_week_learn;
    int week_days = 0;
    long long sum = 0;
    while (++week_days)
    {
        if (sum >= sum_days_rest)
        {
            break;
        }
        sum_days++;
        if (week_days >= 1 && week_days <= 5)
        {
            sum += a;
        }
        else if (week_days >= 6 && week_days <= 7)
        {
            sum += b;
        }
        if (week_days == 7)
        {
            week_days = 0;
        }
    }
    std::cout << sum_days << '\n';
}
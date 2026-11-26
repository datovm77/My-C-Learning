// CSP202605B 机器人宿管指南
#include <iostream>
#include <vector>

using namespace std;
long long n;
long long k, m;

bool check(long long num)
{
    // 在机器人数量为num，初始苹果为n，每日损耗为k，食用天数为m的情况下，是否可行？
    long long nn = n;
    long long kk = k;
    long long mm = m;
    while (mm--)
    {
        nn -= ((1LL * nn * kk + 100 - 1) / 100);
        nn -= num;

        if (nn < 0)
            return false;
    }
    return true;
}

int main()
{
    cin >> n >> k >> m;

    long long l = 0;
    long long r = 1LL * (n / m) + 1;

    long long ans = -1;
    while (l <= r)
    {
        long long mid = l + (r - l) / 2;
        if (check(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    cout << ans << '\n';
}
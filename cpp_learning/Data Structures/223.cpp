// P1115 最大子段和
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<long long> a(n + 1);
    vector<long long> dp(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    dp[1] = a[1];

    long long ans = dp[1];
    for (int i = 2; i <= n; i++)
    {
        dp[i] = max(dp[i - 1] + a[i], a[i]);

        ans = max(ans, dp[i]);
    }

    cout << ans << '\n';
}
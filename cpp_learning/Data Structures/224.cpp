// P1216 数字三角形
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> a(n + 1, vector<int>(n + 1));
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cin >> a[i][j];
        }
    }
    dp[1][1] = a[1][1];

    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (j == 1)
                dp[i][j] = dp[i - 1][j] + a[i][j];
            else if (j == 1)
                dp[i][j] = dp[i - 1][j - 1] + a[i][j];
            else
                dp[i][j] = max(dp[i - 1][j - 1], dp[i - 1][j]) + a[i][j];
        }
    }

    int ans = dp[n][1];
    for (int j = 2; j <= n; j++)
        ans = max(ans, dp[n][j]);

    cout << ans << '\n';
}
// P1616 疯狂的采药（二维完全背包）
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

int main()
{
    int T, M;
    cin >> T >> M;

    vector<pair<int, int>> a(M + 1);

    for (int i = 1; i <= M; i++)
        cin >> a[i].first >> a[i].second;

    vector<vector<long long>> dp(
        M + 1, vector<long long>(T + 1, 0));

    for (int i = 1; i <= M; i++)
    {
        for (int j = 0; j <= T; j++)
        {
            // 不采摘第 i 种草药
            dp[i][j] = dp[i - 1][j];

            // 采摘第 i 种草药
            if (j >= a[i].first)
            {
                dp[i][j] = max(
                    dp[i][j],
                    dp[i][j - a[i].first] + a[i].second);
            }
        }
    }

    cout << dp[M][T];

    return 0;
}
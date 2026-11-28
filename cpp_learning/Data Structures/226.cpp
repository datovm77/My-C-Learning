// P1048 采药（二维 0/1 背包）
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main()
{
    int T, M;
    cin >> T >> M;

    vector<pair<int, int>> a(M + 1);

    for (int i = 1; i <= M; i++)
        cin >> a[i].first >> a[i].second;

    vector<vector<int>> dp(M + 1, vector<int>(T + 1, 0));

    for (int i = 1; i <= M; i++)
    {
        for (int j = 0; j <= T; j++)
        {
            // 不采摘
            dp[i][j] = dp[i - 1][j];

            if (j >= a[i].first)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - a[i].first] + a[i].second);
            }
        }
    }

    cout << dp[M][T];

    return 0;
}

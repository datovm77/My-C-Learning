// P1048 采药（一维 0/1 背包）
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

    vector<int> dp(T + 1, 0);

    for (int i = 1; i <= M; i++)
    {
        int t = a[i].first;
        int v = a[i].second;

        // 倒序遍历，防止重复采摘
        for (int j = T; j >= t; j--)
        {
            dp[j] = max(dp[j], dp[j - t] + v);
        }
    }

    cout << dp[T];

    return 0;
}
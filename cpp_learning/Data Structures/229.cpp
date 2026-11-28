// P1616 疯狂的采药（一维完全背包）
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

    vector<long long> dp(T + 1, 0);

    for (int i = 1; i <= M; i++)
    {
        int t = a[i].first;
        int v = a[i].second;

        // 正序遍历，允许重复采摘
        for (int j = t; j <= T; j++)
        {
            dp[j] = max(dp[j], dp[j - t] + v);
        }
    }

    cout << dp[T];

    return 0;
}
// CSP202412B 梦境巡查
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> a_sum(n + 2, 0);
    vector<long long> b_sum(n + 2, 0);
    vector<long long> b(n + 1, 0);

    // a_sum[j] = a[0] + ... + a[j-1]
    for (int i = 1; i <= n + 1; i++)
    {
        int x;
        cin >> x;
        a_sum[i] = a_sum[i - 1] + x;
    }

    // b_sum[j] = b[1] + ... + b[j-1]
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
        b_sum[i + 1] = b_sum[i] + b[i];
    }

    // 3. 计算每段路程要求的初始能量
    // D[j] 表示：为了成功完成第 j 段路程，初始能量 w 至少需要达到多少。
    vector<long long> D(n + 2);
    for (int i = 1; i <= n + 1; i++)
    {
        D[i] = a_sum[i] - b_sum[i];
    }

    vector<long long> premax(n + 2);
    premax[1] = D[1];

    for (int i = 2; i <= n + 1; i++)
    {
        premax[i] = max(premax[i - 1], D[i]);
    }

    vector<long long> sufmax(n + 2);
    sufmax[n + 1] = D[n + 1];
    for (int i = n; i >= 1; i--)
    {
        sufmax[i] = max(sufmax[i + 1], D[i]);
    }

    // 分别求每个补给失效时的答案
    for (int i = 1; i <= n; i++)
    {
        long long ans = max(premax[i], b[i] + sufmax[i + 1]);
        if (i > 1)
            cout << ' ';
        cout << ans;
    }

    cout << '\n';

    return 0;
}
// P2036 PERKET
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int n;
vector<int> suan, bitter;
int ans = 1000000000;

void dfs(int pos, int S, int B, bool picked)
{
    // 所有食材都考虑完毕
    if (pos == n)
    {
        // 至少选择一种食材
        if (picked)
        {
            ans = min(ans, abs(S - B));
        }
        return;
    }

    // 选择当前食材
    dfs(pos + 1, S * suan[pos],
        B + bitter[pos], true);

    // 不选择当前食材
    dfs(pos + 1, S, B, picked);
}

int main()
{
    cin >> n;

    suan.resize(n);
    bitter.resize(n);

    for (int i = 0; i < n; i++)
    {
        cin >> suan[i] >> bitter[i];
    }

    dfs(0, 1, 0, false);

    cout << ans << '\n';

    return 0;
}

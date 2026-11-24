// P1657 选书
#include <iostream>
#include <vector>
#include <utility>
using namespace std;

int n;
int ans = 0;

vector<pair<int, int>> love;
vector<int> vis;

void dfs(int s)
{
    if (s == n)
    {
        ans++;
        return;
    }

    auto [x, y] = love[s];

    // 当前人选择书 x
    if (!vis[x])
    {
        vis[x] = 1;
        dfs(s + 1);
        vis[x] = 0;
    }

    // 当前人选择书 y
    if (!vis[y])
    {
        vis[y] = 1;
        dfs(s + 1);
        vis[y] = 0;
    }
}

int main()
{
    cin >> n;

    love.resize(n);
    vis.assign(n + 1, 0);

    for (int i = 0; i < n; i++)
        cin >> love[i].first >> love[i].second;

    dfs(0);

    cout << ans << '\n';

    return 0;
}

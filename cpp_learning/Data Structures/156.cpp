#include <iostream>
#include <vector>
using namespace std;

void dfs(int u,
         const vector<vector<int>> &g,
         vector<int> &vis)
{
    // 标记当前节点已经访问过
    vis[u] = 1;

    cout << u << " ";

    // 遍历当前节点的所有邻居
    for (int v : g[u])
    {
        if (vis[v] == 0)
        {
            dfs(v, g, vis);
        }
    }
}

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> g(n + 1);

    // 无向图建边
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> vis(n + 1, 0);

    int ans = 0;

    for (int i = 1; i <= n; i++)
    {
        if (vis[i] == 0)
        {
            ans++;

            dfs(i, g, vis);

            cout << '\n';
        }
    }

    cout << "连通块数量: " << ans << '\n';

    return 0;
}
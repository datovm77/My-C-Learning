#include <iostream>
#include <vector>
#include <queue>

int main()
{
    int n, m;
    if (!(std::cin >> n >> m))
        return 0;
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        std::cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    std::vector<int> dist(n + 1, -1);
    std::queue<int> q;

    dist[1] = 0;
    q.push(1);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : g[u])
        {
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    for (int i = 1; i <= n; i++)
    {
        std::cout << "1到" << i << "的最短距离为" << dist[i] << '\n';
    }

    return 0;
}
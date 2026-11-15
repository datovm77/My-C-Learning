// P8662 [蓝桥杯 2018 省 AB] 全球变暖
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <utility>
std::vector<std::string> g;
std::vector<std::vector<int>> vis;
int N;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
long long ans = 0;
bool bfs(int sx, int sy)
{
    std::queue<std::pair<int, int>> q;
    q.push({sx, sy});
    vis[sx][sy] = 1;

    bool hasSafe = false;

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        bool willSink = false;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 ||
                nx >= N || ny >= N)
            {
                willSink = true;
                continue;
            }

            if (g[nx][ny] == '.')
            {
                willSink = true;
            }
            else if (!vis[nx][ny])
            {
                vis[nx][ny] = 1;
                q.push({nx, ny});
            }
        }

        if (!willSink)
        {
            hasSafe = true;
        }
    }
    return hasSafe;
}

int main()
{
    std::cin >> N;
    g.resize(N);
    vis.assign(N, std::vector<int>(N, 0));
    for (int i = 0; i < N; i++)
    {
        std::cin >> g[i];
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (g[i][j] == '#' && !vis[i][j])
            {
                bool hasSafe = bfs(i, j);
                if (!hasSafe)
                {
                    ans++;
                }
            }
        }
    }

    std::cout << ans << '\n';
}
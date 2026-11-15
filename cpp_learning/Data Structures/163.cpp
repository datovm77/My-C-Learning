// P1605 迷宫
#include <iostream>
#include <vector>

std::vector<std::vector<int>> g;
std::vector<std::vector<int>> vis;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int N, M, T;
long long ans = 0;

void dfs(int x, int y)
{
    vis[x][y] = 1;

    if (g[x][y] == 2)
    {
        ans++;
        vis[x][y] = 0;
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 越界
        if (nx < 0 || nx >= N ||
            ny < 0 || ny >= M)
            continue;

        // 障碍物
        if (g[nx][ny] == 0)
            continue;

        if (vis[nx][ny])
            continue;
        dfs(nx, ny);
    }
    vis[x][y] = 0;
}

int main()
{

    if (!(std::cin >> N >> M >> T))
        return 0;

    g.assign(N, std::vector<int>(M, 1));
    vis.assign(N, std::vector<int>(M, 0));
    int sx, sy, fx, fy;
    if (!(std::cin >> sx >> sy >> fx >> fy))
        return 0;
    g[fx - 1][fy - 1] = 2;
    for (int i = 0; i < T; i++)
    {
        int x, y;
        std::cin >> x >> y;
        g[x - 1][y - 1] = 0;
    }
    if (g[sx - 1][sy - 1] == 0)
    {
        std::cout << 0 << '\n';
        return 0;
    }
    dfs(sx - 1, sy - 1);
    std::cout << ans << "\n";
}
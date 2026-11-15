// P1683 入门
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

std::vector<std::string> g;
std::vector<std::vector<int>> path;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int W, H;
int x_b, y_b;
int max = 0;

int dfs(int x, int y)
{
    path[x][y] = 1;
    int cnt = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= H || ny >= W)
        {
            continue;
        }

        if (g[nx][ny] == '#')
        {
            continue;
        }
        if (path[nx][ny])
        {
            continue;
        }
        cnt += dfs(nx, ny);
    }
    return cnt;
}

int main()
{

    if (!(std::cin >> W >> H))
        return 0;

    g.resize(H);
    std::vector<std::vector<int>> paths(H, std::vector<int>(W, 0));
    path = paths;
    for (int i = 0; i < H; i++)
    {
        std::cin >> g[i];
        auto p = std::find(g[i].begin(), g[i].end(), '@');
        if (p != g[i].end())
        {
            x_b = i;
            y_b = p - g[i].begin();
        }
    }
    int result = dfs(x_b, y_b);

    std::cout << result << '\n';
}
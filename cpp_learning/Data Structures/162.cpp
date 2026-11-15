// P1596 [USACO10OCT] Lake Counting S
#include <iostream>
#include <vector>

std::vector<std::string> g;
int dx[] = {-1, 1, 0, 0, -1, 1, -1, 1};
int dy[] = {0, 0, -1, 1, -1, -1, 1, 1};
int N, M;

void dfs(int x, int y)
{
    g[x][y] = '.';

    for (int i = 0; i < 8; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= N || ny >= M)
        {
            continue;
        }
        if (g[nx][ny] == 'W')
        {
            dfs(nx, ny);
        }
    }
}

int main()
{
    if (!(std::cin >> N >> M))
        return 0;
    g.resize(N);
    for (int i = 0; i < N; i++)
    {
        std::cin >> g[i];
    }

    int ans = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            if (g[i][j] == 'W')
            {
                ans++;
                dfs(i, j);
            }
        }
    }
    std::cout << ans << '\n';
}
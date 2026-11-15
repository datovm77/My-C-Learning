// P1451 求细胞数量
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> v;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int n, m;

void dfs(int x, int y)
{
    v[x][y] = '0';

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
        {
            continue;
        }
        if (v[nx][ny] != '0')
        {
            dfs(nx, ny);
        }
    }
}

int main()
{

    if (!(std::cin >> n >> m))
        return 0;
    v.resize(n);
    for (int i = 0; i < n; i++)
    {
        std::cin >> v[i];
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] != '0')
            {
                ans++;
                dfs(i, j);
            }
        }
    }
    std::cout << ans << '\n';
}
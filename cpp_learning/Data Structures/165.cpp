// P1162 填涂颜色

#include <iostream>
#include <vector>
using namespace std;

int n;
vector<vector<int>> g;
vector<vector<int>> vis;

// 上、下、左、右
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

// 标记所有与边界连通的 0
void dfs(int x, int y)
{
    vis[x][y] = 1;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        // 1. 越界
        if (nx < 0 || nx >= n ||
            ny < 0 || ny >= n)
            continue;

        // 2. 不是 0，或者已经访问过
        if (g[nx][ny] != 0 || vis[nx][ny])
            continue;

        // 3. 继续搜索
        dfs(nx, ny);
    }
}

int main()
{
    cin >> n;

    g.resize(n, vector<int>(n));
    vis.resize(n, vector<int>(n, 0));

    // 输入矩阵
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> g[i][j];

    // 第一步：从边界上的所有 0 出发
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            bool border = (i == 0 || i == n - 1 ||
                           j == 0 || j == n - 1);

            if (border && g[i][j] == 0 && !vis[i][j])
                dfs(i, j);
        }
    }

    // 第二步：把未访问的 0 改成 2
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (g[i][j] == 0 && !vis[i][j])
                g[i][j] = 2;
        }
    }

    // 输出矩阵
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j > 0)
                cout << " ";
            cout << g[i][j];
        }
        cout << '\n';
    }

    return 0;
}

// P1434 滑雪
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int R, C;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

vector<vector<int>> a;
vector<vector<int>> dp;

int dfs(int x, int y)
{
    if (dp[x][y] != 0)
        return dp[x][y];

    dp[x][y] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < R && ny >= 0 && ny < C && a[nx][ny] < a[x][y])
        {
            dp[x][y] = max(dp[x][y], dfs(nx, ny) + 1);
        }
    }
    return dp[x][y];
}

int main()
{
    cin >> R >> C;
    a.assign(R, vector<int>(C));
    dp.assign(R, vector<int>(C, 0));
    for (int i = 0; i < R; i++)
        for (int j = 0; j < C; j++)
            cin >> a[i][j];

    int ans = 0;

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            ans = max(ans, dfs(i, j));
        }
    }

    cout << ans << '\n';
}
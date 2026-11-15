#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

const long long MOD = 1000000007;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<string> g(n);

    for (int i = 0; i < n; i++)
        cin >> g[i];

    if (g[0][0] == '#' ||
        g[n - 1][m - 1] == '#')
    {
        cout << "-1 0\n";
        return 0;
    }

        vector<vector<int>> dist(
        n, vector<int>(m, -1));

    vector<vector<long long>> ways(
        n, vector<long long>(m, 0));

    queue<pair<int, int>> q;

    dist[0][0] = 0;
    ways[0][0] = 1;

    q.push({0, 0});

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || nx >= n ||
                ny < 0 || ny >= m)
                continue;

            if (g[nx][ny] == '#')
                continue;

            // 首次发现这个格子
            if (dist[nx][ny] == -1)
            {
                dist[nx][ny] = dist[x][y] + 1;

                ways[nx][ny] = ways[x][y];

                q.push({nx, ny});
            }
            // 找到另一条同样短的路径
            else if (dist[nx][ny] == dist[x][y] + 1)
            {
                ways[nx][ny] =
                    (ways[nx][ny] + ways[x][y]) % MOD;
            }
        }
    }

    int d = dist[n - 1][m - 1];
    long long w = ways[n - 1][m - 1];

    cout << d << " " << w << '\n';

    return 0;
}
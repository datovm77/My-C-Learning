// P2802 回家
#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<vector<int>> v(n, vector<int>(m));

    int sx = 0, sy = 0;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];

            if (v[i][j] == 2)
            {
                sx = i;
                sy = j;
            }
        }
    }

    vector<vector<vector<int>>> dist(
        n, vector<vector<int>>(m, vector<int>(7, -1)));

    queue<tuple<int, int, int>> q;

    // 起点，满血 6，步数 0
    q.push({sx, sy, 6});
    dist[sx][sy][6] = 0;

    while (!q.empty())
    {
        auto [x, y, hp] = q.front();
        q.pop();

        // 活着到达终点
        if (v[x][y] == 3)
        {
            cout << dist[x][y][hp] << '\n';
            return 0;
        }

        // 再移动一步就会死亡
        if (hp <= 1)
            continue;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 ||
                nx >= n || ny >= m ||
                v[nx][ny] == 0)
            {
                continue;
            }

            // 移动消耗 1 点血
            int nextHp = hp - 1;

            // 活着到达鼠标位置，补满血
            if (v[nx][ny] == 4)
                nextHp = 6;

            // 这个状态已经搜索过
            if (dist[nx][ny][nextHp] != -1)
                continue;

            dist[nx][ny][nextHp] =
                dist[x][y][hp] + 1;

            q.push({nx, ny, nextHp});
        }
    }

    cout << -1 << '\n';

    return 0;
}
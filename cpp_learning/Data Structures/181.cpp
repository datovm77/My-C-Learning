// P2802 回家
#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int n, m;
vector<vector<int>> v;
queue<pair<int, int>> q;
vector<vector<int>> blood_map;
vector<vector<int>> vis;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main()
{
    cin >> n >> m;
    v.assign(n, vector<int>(m));
    blood_map.assign(n, vector<int>(m, -1));
    vis.assign(n, vector<int>(m, -1));
    int x_end, y_end;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
            if (v[i][j] == 2)
            {
                q.push({i, j});
                blood_map[i][j] = 6;
                vis[i][j] = 0;
            }
            else if (v[i][j] == 3)
            {
                x_end = i;
                y_end = j;
            }
        }
    }

    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        if (v[x][y] == 4 && blood_map[x][y] > 0)
        {
            blood_map[x][y] = 6;
        }
        if (v[x][y] == 3 && blood_map[x][y] > 0)
        {
            cout << vis[x][y] << '\n';
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= m || v[nx][ny] == 0 || (blood_map[x][y] <= blood_map[nx][ny]))
            {
                continue;
            }
            blood_map[nx][ny] = blood_map[x][y] - 1;
            vis[nx][ny] = vis[x][y] + 1;
            q.push({nx, ny});
        }
    }

    if (blood_map[x_end][y_end] <= 0)
    {
        cout << "-1" << '\n';
    }
}
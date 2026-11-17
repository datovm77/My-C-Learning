// P1443 马的遍历
#include <iostream>
#include <queue>
#include <vector>
#include <utility>
using namespace std;

queue<pair<int, int>> q;
vector<vector<int>> disk;
int dx[] = {-1, 1, 2, -2, -1, 1, 2, -2};
int dy[] = {2, 2, 1, 1, -2, -2, -1, -1};
int main()
{
    int n, m, x, y;
    if (!(cin >> n >> m >> x >> y))
        return 0;
    disk.assign(n + 1, vector<int>(m + 1, -1));
    disk[x][y] = 0;
    q.push({x, y});
    while (!q.empty())
    {
        auto [x, y] = q.front();
        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 1 || ny < 1 || nx > n || ny > m || disk[nx][ny] != -1)
            {
                continue;
            }
            disk[nx][ny] = disk[x][y] + 1;
            q.push({nx, ny});
        }
        q.pop();
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (j != 1)
                cout << ' ';
            cout << disk[i][j];
        }
        cout << '\n';
    }

    return 0;
}
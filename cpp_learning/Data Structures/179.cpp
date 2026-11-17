// P1747 好奇怪的游戏
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;
queue<pair<int, int>> q;
vector<vector<int>> dis;
int dx[] = {1, 1, 2, 2, -1, -1, -2, -2, 2, 2, -2, -2};
int dy[] = {-2, 2, 1, -1, 2, -2, 1, -1, 2, -2, 2, -2};
int main()
{
    int x1, y1;
    cin >> x1 >> y1;
    int x2, y2;
    cin >> x2 >> y2;

    dis.assign(500, vector<int>(500, -1));
    dis[1][1] = 0;
    q.push({1, 1});

    while (!q.empty() && (dis[x1][y1] == -1 || dis[x2][y2] == -1))
    {
        auto [x, y] = q.front();
        for (int i = 0; i < 12; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx <= 0 || ny <= 0 || nx >= 500 || ny >= 500 || dis[nx][ny] != -1)
            {
                continue;
            }
            dis[nx][ny] = dis[x][y] + 1;
            q.push({nx, ny});
        }
        q.pop();
    }
    cout << dis[x1][y1] << '\n';
    cout << dis[x2][y2] << '\n';
}
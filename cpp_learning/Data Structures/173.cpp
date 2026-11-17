// P1746 离开中山路
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <utility>
using namespace std;
vector<vector<int>> map;
queue<pair<int, int>> q;
vector<vector<int>> disk;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
int main()
{
    int n;
    if (!(std::cin >> n))
        return 0;
    map.assign(n + 1, vector<int>(n + 1, 0));
    disk.assign(n + 1, vector<int>(n + 1, -1));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char ch;
            cin >> ch;
            map[i][j] = ch - '0';
        }
    }
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    disk[x1][y1] = 0;
    q.push({x1, y1});
    while (!q.empty())
    {
        auto [x, y] = q.front();
        if (x == x2 && y == y2)
        {
            break;
        }
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx <= 0 || ny <= 0 || nx > n || ny > n || disk[nx][ny] != -1 || map[nx][ny] == 1)
            {
                continue;
            }
            disk[nx][ny] = disk[x][y] + 1;
            q.push({nx, ny});
        }
        q.pop();
    }
    cout << disk[x2][y2] << '\n';
    return 0;
}
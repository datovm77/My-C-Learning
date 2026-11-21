// P1141 01迷宫
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int n, m;
vector<vector<int>> v;
vector<vector<int>> belong;
vector<int> componentSize;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
void BFS(int x1, int y1, int num)
{
    int cnt = 0;
    queue<pair<int, int>> q;
    belong[x1][y1] = num;
    q.push({x1, y1});
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();
        cnt++;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= n || ny >= n || belong[nx][ny] != -1 || (v[x][y] == v[nx][ny]))
            {
                continue;
            }
            belong[nx][ny] = num;
            q.push({nx, ny});
        }
    }
    componentSize[num] = cnt;
}

int main()
{

    cin >> n >> m;

    v.assign(n, vector<int>(n));
    belong.assign(n, vector<int>(n, -1));
    componentSize.resize(n * n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            char c;
            cin >> c;
            v[i][j] = c - '0';
        }
    }
    int num = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (belong[i][j] == -1)
            {
                BFS(i, j, num);
                num++;
            }
        }
    }

    while (m--)
    {
        int x, y;
        cin >> x >> y;
        cout << componentSize[belong[x - 1][y - 1]] << '\n';
    }
    return 0;
}
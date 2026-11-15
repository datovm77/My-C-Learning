// P1141 01迷宫
#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;
int n, m;

vector<string> g;
// id[x][y] 表示这个格子所属的连通块编号
vector<vector<int>> id;

// sz[k] 表示编号为 k 的连通块大小
vector<int> sz(1, 0);

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

int component = 0;

void bfs(int sx, int sy)
{
    component++;
    queue<pair<int, int>> q;

    q.push({sx, sy});
    id[sx][sy] = component;

    int cnt = 0;
    while (!q.empty())
    {
    }
}

int main()
{
    cin >> n >> m;
    g.resize(n);
    id.assign(n, vector<int>(n, 0));

    for (int i = 0; i < n; i++)
        cin >> g[i];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (id[i][j] == 0)
            {
                bfs(i, j);
            }
        }
    }
}

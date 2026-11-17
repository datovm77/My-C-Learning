// P1332 血色先锋队
#include <iostream>
#include <vector>
#include <queue>
#include <utility>
using namespace std;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, a, b;
    cin >> n >> m >> a >> b;

    vector<vector<int>> dis(
        n + 1, vector<int>(m + 1, -1));

    queue<pair<int, int>> q;

    // 1. 初始化所有感染源
    for (int i = 0; i < a; i++)
    {
        int x, y;
        cin >> x >> y;

        if (dis[x][y] == -1)
        {
            dis[x][y] = 0;
            q.push({x, y});
        }
    }

    // 2. 保存领主的位置
    vector<pair<int, int>> lord(b);

    for (int i = 0; i < b; i++)
    {
        cin >> lord[i].first >> lord[i].second;
    }

    // 3. 多源 BFS
    while (!q.empty())
    {
        auto [x, y] = q.front();
        q.pop();

        for (int j = 0; j < 4; j++)
        {
            int nx = x + dx[j];
            int ny = y + dy[j];

            if (nx < 1 || nx > n ||
                ny < 1 || ny > m ||
                dis[nx][ny] != -1)
            {
                continue;
            }

            dis[nx][ny] = dis[x][y] + 1;
            q.push({nx, ny});
        }
    }

    // 4. 按输入顺序输出每个领主的感染时间
    for (int i = 0; i < b; i++)
    {
        auto [x, y] = lord[i];
        cout << dis[x][y] << '\n';
    }

    return 0;
}
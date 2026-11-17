// P2385 Bronze Lilypad Pond B
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> v;
vector<vector<int>> disk;
queue<pair<int, int>> q;
int main()
{
    int M, N, M1, M2;
    if (!(std::cin >> M >> N >> M1 >> M2))
        return 0;

    v.assign(M, vector<int>(N));
    disk.assign(M, vector<int>(N, -1));
    int dx[] = {M1, M2, -M1, -M2, M1, M2, -M1, -M2};
    int dy[] = {M2, -M1, M2, M1, -M2, M1, -M2, -M1};
    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < N; j++)
        {
            cin >> v[i][j];
            if (v[i][j] == 3)
            {
                q.push({i, j});
                disk[i][j] = 0;
            }
        }
    }
    int end_x = 0, end_y = 0;
    while (!q.empty())
    {
        auto [x, y] = q.front();
        if (v[x][y] == 4)
        {
            end_x = x;
            end_y = y;
            break;
        }
        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx < 0 || ny < 0 || nx >= M || ny >= N || v[nx][ny] == 0 || v[nx][ny] == 2 || disk[nx][ny] != -1)
            {
                continue;
            }
            q.push({nx, ny});
            disk[nx][ny] = disk[x][y] + 1;
        }
        q.pop();
    }
    std::cout << disk[end_x][end_y] << '\n';
}
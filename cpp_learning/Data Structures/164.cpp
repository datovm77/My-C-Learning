// P1644 跳马问题
#include <iostream>
// 旧写法: #include <vector> (本题单向搜索无需 visited 数组)

int dx[4] = {-2, -1, 1, 2};
int dy[4] = {1, 2, 2, 1};
int n, m;
long long total = 0;
// 旧写法: std::vector<std::vector<int>> v; (未实际使用，且易越界)

void dfs(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx < 0 || ny < 0 || nx > n || ny > m)
        {
            continue;
        }
        if (nx == n && ny == m)
        {
            total++;
            continue;                     // 旧写法: 无 continue; (到达终点后仍多余调用下一层 dfs)
        }
        dfs(nx, ny);
    }
}

int main()
{
    if (!(std::cin >> n >> m))
        return 0;
    // 旧写法: v.resize(n, std::vector<int>(m, 1)); (冗余内存分配)
    dfs(0, 0);
    std::cout << total << '\n';

    return 0;
}

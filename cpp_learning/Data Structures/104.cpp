// P3397 地毯
#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(0);
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> v1(n + 2, std::vector<int>(n + 2, 0));
    std::vector<std::vector<int>> d1(n + 2, std::vector<int>(n + 2, 0));
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            d1[i][j] = v1[i][j] - v1[i - 1][j] - v1[i][j - 1] + v1[i - 1][j - 1];
        }
    }

    while (m--)
    {
        int x1, y1, x2, y2;
        std::cin >> x1 >> y1 >> x2 >> y2;
        d1[x1][y1] += 1;
        d1[x1][y2 + 1] -= 1;
        d1[x2 + 1][y1] -= 1;
        d1[x2 + 1][y2 + 1] += 1;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            v1[i][j] = d1[i][j] + v1[i - 1][j] + v1[i][j - 1] - v1[i - 1][j - 1];
            if (j != 1)
                std::cout << ' ';
            std::cout << v1[i][j];
        }
        std::cout << '\n';
    }

    return 0;
}
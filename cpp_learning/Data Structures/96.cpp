#include <iostream>
#include <vector>
#include <limits>
int main()
{
    std::ios::sync_with_stdio(0);
    std::cin.tie(nullptr);

    int N, M, C;
    if (!(std::cin >> N >> M >> C))
        return 0;
    std::vector<std::vector<long long>> map(N + 2, std::vector<long long>(M + 2, 0));

    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            std::cin >> map[i][j];
        }
    }

    std::vector<std::vector<long long>> sum(N + 2, std::vector<long long>(M + 2, 0));

    for (int i = N; i >= 1; i--)
    {
        for (int j = M; j >= 1; j--)
        {
            sum[i][j] = sum[i + 1][j] + sum[i][j + 1] - sum[i + 1][j + 1] + map[i][j];
        }
    }

    long long max = std::numeric_limits<long long>::min();
    int X, Y;
    for (int i = 1; i <= N - C + 1; i++)
    {
        for (int j = 1; j <= M - C + 1; j++)
        {
            long long value = sum[i][j] - sum[i + C][j] - sum[i][j + C] + sum[i + C][j + C];
            if (value > max)
            {
                max = value;
                X = i;
                Y = j;
            }
        }
    }

    std::cout << X << ' ' << Y << '\n';
}
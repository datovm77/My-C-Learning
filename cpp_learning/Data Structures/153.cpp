#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>

int main()
{
    int T;
    std::cin >> T;

    while (T--)
    {
        char type;
        int n;

        std::cin >> type >> n;

        std::vector<std::string> name(n);
        std::unordered_map<std::string, int> id;

        for (int i = 0; i < n; i++)
        {
            std::cin >> name[i];
            id[name[i]] = i;
        }

        // 建立临接矩阵
        std::vector<std::vector<int>> g(n, std::vector<int>(n, 0));

        int m;
        std::cin >> m;
        for (int i = 0; i < m; i++)
        {
            std::string a, b;
            std::cin >> a >> b;

            int u = id[a];
            int v = id[b];

            g[u][v] = 1;
            if (type == 'U')
            {
                g[v][u] = 1;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j > 0)
                    std::cout << ' ';
                std::cout << g[i][j];
            }
            std::cout << '\n';
        }
        std::vector<int> indegree(n, 0);
        std::vector<int> outdegree(n, 0);
        std::vector<int> degree(n, 0);

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                outdegree[i] += g[i][j];
                indegree[i] += g[j][i];
            }

            if (type == 'D')
            {
                degree[i] = indegree[i] + outdegree[i];
            }
            else
            {
                degree[i] = outdegree[i] + g[i][i];
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (degree[i] == 0)
            {
                continue;
            }

            std::cout << name[i] << ": ";

            if (type == 'D')
            {
                std::cout << outdegree[i] << ' ' << indegree[i] << ' ' << degree[i] << '\n';
            }
            else
            {
                std::cout << degree[i] << '\n';
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (degree[i] == 0)
            {
                std::cout << name[i] << "\n";
            }
        }
    }
    return 0;
}
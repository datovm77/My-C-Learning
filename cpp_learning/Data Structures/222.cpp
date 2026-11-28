// CSP202312A 仓库规划
#include <iostream>
#include <vector>
using namespace std;
int n, m;

vector<vector<int>> v;

int main()
{
    cin >> n >> m;
    v.assign(n + 1, vector<int>(m));

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }

    for (int i = 1; i <= n; i++)
    {
        int parent = 0;
        for (int j = 1; j <= n; j++)
        {
            if (j == i)
                continue;
            bool ok = true;
            for (int k = 0; k < m; k++)
            {
                if (v[j][k] <= v[i][k])
                {
                    ok = false;
                    break;
                }
            }
            if (ok)
            {
                parent = j;
                break;
            }
        }
        cout << parent << '\n';
    }
}
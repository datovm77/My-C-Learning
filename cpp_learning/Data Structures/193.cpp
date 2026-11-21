// CSP202406A 矩阵重塑（其一）
#include <iostream>
#include <vector>

using namespace std;
vector<vector<int>> MM;
int n, m, p, q;
int main()
{
    cin >> n >> m >> p >> q;
    MM.assign(p, vector<int>(q));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int number;
            cin >> number;

            int k = i * m + j;

            int x = k / q;
            int y = k % q;
            MM[x][y] = number;
        }
    }
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            if (j)
                cout << ' ';
            cout << MM[i][j];
        }
        cout << '\n';
    }

    return 0;
}
// CSP202406B 矩阵重塑（其二）
#include <iostream>
#include <vector>
using namespace std;
int n, m, t;
vector<vector<int>> v;

vector<vector<int>> v_reshape(const vector<vector<int>> &v, int p, int q)
{
    int nn = (int)v.size();
    int mm = (int)v[0].size();
    vector<vector<int>> v_reshape;
    v_reshape.assign(p, vector<int>(q));
    for (int i = 0; i < nn; i++)
    {
        for (int j = 0; j < mm; j++)
        {
            int number = v[i][j];
            int k = i * mm + j;

            int x = k / q;
            int y = k % q;
            v_reshape[x][y] = number;
        }
    }
    return v_reshape;
}
vector<vector<int>> v_tranf(const vector<vector<int>> &v, int p, int q)
{
    int nn = (int)v.size();
    int mm = (int)v[0].size();
    vector<vector<int>> v_tranf;
    v_tranf.assign(mm, vector<int>(nn));
    for (int i = 0; i < nn; i++)
    {
        for (int j = 0; j < mm; j++)
        {
            int number = v[i][j];
            v_tranf[j][i] = number;
        }
    }
    return v_tranf;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> m >> t;
    v.resize(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
        }
    }

    while (t--)
    {
        int o, a, b;
        cin >> o >> a >> b;
        if (o == 1)
        {
            v = v_reshape(v, a, b);
        }
        else if (o == 2)
        {
            v = v_tranf(v, a, b);
        }
        else if (o == 3)
        {
            cout << v[a][b] << '\n';
        }
    }

    return 0;
}
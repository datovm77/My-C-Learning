// CSP202406B 矩阵重塑（其二）
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, t;
    cin >> n >> m >> t;

    int rows = n, cols = m;
    vector<int> v(n * m);
    vector<int> tmp(n * m);

    for (int i = 0; i < n * m; i++)
        cin >> v[i];

    while (t--)
    {
        int op, a, b;
        cin >> op >> a >> b;

        if (op == 1)
        {
            // 重塑：只修改行列数
            rows = a;
            cols = b;
        }
        else if (op == 2)
        {
            // 转置：实际重新排列数据
            for (int i = 0; i < rows; i++)
            {
                for (int j = 0; j < cols; j++)
                {
                    tmp[j * rows + i] =
                        v[i * cols + j];
                }
            }

            v.swap(tmp);
            swap(rows, cols);
        }
        else if (op == 3)
        {
            // 查询：二维坐标转一维下标
            cout << v[a * cols + b] << '\n';
        }
    }

    return 0;
}

// CSP202406B 矩阵重塑（其二）
#include <iostream>
#include <utility>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long rows, cols;
    int t;
    cin >> rows >> cols >> t;

    const long long N = rows * cols;
    vector<int> data(N);
    for (int &x : data)
        cin >> x;

    long long mul = 1; // 当前一维下标 -> 原始一维下标的系数

    while (t--)
    {
        int op;
        long long a, b;
        cin >> op >> a >> b;

        if (op == 1)
        {
            rows = a;
            cols = b;
        }
        else if (op == 2)
        {
            if (N > 1)
                mul = mul * cols % (N - 1); // 用转置前的列数
            swap(rows, cols);
        }
        else if (op == 3)
        {
            long long k = a * cols + b;
            long long original = (k == N - 1) ? k : k * mul % (N - 1);
            cout << data[original] << '\n';
        }
    }
}
// CSP202509B 水印检查（枚举阈值）
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
int n, L;
vector<vector<int>> photo;

// 当灰度大于等于k为1，表示白色。反之则为黑色,为-1。
vector<vector<int>> b_w;
vector<vector<int>> CSP = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, -1, -1, 1, -1, -1, 1, -1, 1},
    {1, -1, -1, 1, 1, 1, 1, 1, -1},
    {1, -1, -1, -1, -1, 1, 1, -1, -1},
    {1, 1, 1, 1, 1, 1, 1, -1, -1}};

const int num = 29;

bool check_min(int x, int y)
{
    if (x + 4 >= n || y + 8 >= n)
    {
        return false;
    }
    for (int i = x; i < x + 5; i++)
    {
        for (int j = y; j < y + 9; j++)
        {
            if (b_w[i][j] != CSP[i - x][j - y])
            {
                return false;
            }
        }
    }

    return true;
}

bool check_s()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (check_min(i, j))
                return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    cin >> n >> L;
    photo.assign(n, vector<int>(n));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> photo[i][j];
        }
    }

    int k = 0;
    while (k <= (L - 1))
    {
        b_w.assign(n, vector<int>(n, -1));
        k++;
        for (int i = 0; i < n; i++)
        {

            int j_sum = 0;
            for (int j = 0; j < n; j++)
            {

                if (photo[i][j] >= k)
                {
                    b_w[i][j] = 1;
                    j_sum++;
                }
            }
        }

        if (check_s())
        {
            cout << k << '\n';
        }
    }

    return 0;
}
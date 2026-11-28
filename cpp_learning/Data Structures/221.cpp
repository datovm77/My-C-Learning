// CSP202509B 水印检查（差分）
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, L;

vector<vector<int>> photo;
vector<int> diff;

vector<vector<int>> CSP = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, -1, -1, 1, -1, -1, 1, -1, 1},
    {1, -1, -1, 1, 1, 1, 1, 1, -1},
    {1, -1, -1, -1, -1, 1, 1, -1, -1},
    {1, 1, 1, 1, 1, 1, 1, -1, -1}};

// 计算当前位置的合法阈值区间
void check_min(int x, int y)
{
    int max_black = 0;
    int min_white = L - 1;

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            int val = photo[x + i][y + j];

            if (CSP[i][j] == 1)
            {
                min_white = min(min_white, val);
            }
            else
            {
                max_black = max(max_black, val);
            }
        }
    }

    int l = max_black + 1;
    int r = min_white;

    // 差分数组标记合法区间
    if (l <= r)
    {
        diff[l]++;
        diff[r + 1]--;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> L;

    photo.assign(n, vector<int>(n));
    diff.assign(L + 1, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> photo[i][j];
        }
    }

    // 枚举所有可能的水印左上角
    for (int i = 0; i <= n - 5; i++)
    {
        for (int j = 0; j <= n - 9; j++)
        {
            check_min(i, j);
        }
    }

    // 对差分数组求前缀和
    int sum = 0;

    for (int k = 1; k < L; k++)
    {
        sum += diff[k];

        if (sum > 0)
        {
            cout << k << '\n';
        }
    }

    return 0;
}
// CSP202104B 邻域均值
#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> image;
vector<vector<int>> ima_pre;
int n, L, r, t;
long long sum = 0;

void buildPreSum()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            ima_pre[i][j] = ima_pre[i - 1][j] + ima_pre[i][j - 1] + image[i - 1][j - 1] - ima_pre[i - 1][j - 1];
            // ima_pre[i][j] = ima_pre[i - 1][j] + ima_pre[i][j + 1] + image[i - 1][j - 1] - ima_pre[i - 1][j - 1];
        }
    }
}

int fastq(int x, int y, int &count)
{
    int x1 = max(0, x - r);
    int x2 = min(x + r, n - 1);
    int y1 = max(0, y - r);
    int y2 = min(y + r, n - 1);

    count = (x2 - x1 + 1) * (y2 - y1 + 1);
    return ima_pre[x2 + 1][y2 + 1] - ima_pre[x1][y2 + 1] - ima_pre[x2 + 1][y1] + ima_pre[x1][y1];
}

int main()
{
    cin >> n >> L >> r >> t;
    image.assign(n, vector<int>(n, 0));
    ima_pre.assign(n + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> image[i][j];
        }
    }

    buildPreSum();

    for (int i = 0; i < n; i++)
    // for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < n; j++)
        // for (int j = 1; j <= n; j++)
        {
            int count;
            int sum_t = fastq(i, j, count);
            if (sum_t <= 1LL * t * count)
                // if ((sum_t / count) <= t)
                sum++;
        }
    }

    cout << sum << '\n';
}
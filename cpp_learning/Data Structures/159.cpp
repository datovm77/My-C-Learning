// P5461 赦免战俘
#include <iostream>
#include <vector>

void cheat_free(std::vector<std::vector<int>> &v, int left, int right, int top, int down)
{
    if (left >= right || top >= down)
        return;

    int mid_lf = left + (right - left) / 2;
    int mid_td = top + (down - top) / 2;
    for (int i = left; i <= mid_lf; i++)
    {
        for (int j = top; j <= mid_td; j++)
        {
            v[i][j] = 0;
        }
    }
    cheat_free(v, mid_lf + 1, right, top, mid_td);
    cheat_free(v, left, mid_lf, mid_td + 1, down);
    cheat_free(v, mid_lf + 1, right, mid_td + 1, down);
}

int main()
{
    int n;
    if (!(std::cin >> n))
        return 0;
    int len = 1;
    for (int i = 0; i < n; i++)
    {
        len *= 2;
    }
    std::vector<std::vector<int>> v(len, std::vector<int>(len, 1));
    int left = 0;
    int right = len - 1;
    int top = 0;
    int down = len - 1;
    cheat_free(v, left, right, top, down);
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len; j++)
        {
            if (j != 0)
                std::cout << ' ';
            std::cout << v[i][j];
        }
        std::cout << '\n';
    }
}
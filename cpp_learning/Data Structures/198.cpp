// P2036 PERKET
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
vector<int> bitter;
vector<int> bitter_path;
vector<int> bitter_path_sum;
vector<int> suan;
vector<int> suan_path;
vector<int> suan_path_sum;
int n;

void dfs(int pos, int mode)
{
    if (pos >= n)
    {

        // 为0时乘模式，计算总酸度，为1时计算总苦度
        if (mode == 0)
        {
            int sum = 1;

            for (int x : suan_path)
            {
                sum *= x;
            }
            if (!suan_path.empty())
            {
                suan_path_sum.push_back(sum);
            }
        }
        else if (mode)
        {
            int sum = 0;
            for (int x : bitter_path)
            {
                sum += x;
            }
            if (!bitter_path.empty())
            {
                bitter_path_sum.push_back(sum);
            }
        }

        return;
    }

    if (mode == 0)
    {
        suan_path.push_back(suan[pos]);
        dfs(pos + 1, mode);
        suan_path.pop_back();

        dfs(pos + 1, mode);
    }
    else if (mode)
    {
        bitter_path.push_back(bitter[pos]);
        dfs(pos + 1, mode);
        bitter_path.pop_back();

        dfs(pos + 1, mode);
    }
}

int main()
{
    cin >> n;
    int tt = n;
    while (tt--)
    {
        int bitt, s;
        cin >> s >> bitt;
        bitter.push_back(bitt);
        suan.push_back(s);
    }
    dfs(0, 0);
    dfs(0, 1);

    int s_size = (int)suan_path_sum.size();

    int div = 1000000000;
    for (int i = 0; i < s_size; i++)
    {

        int t = abs(suan_path_sum[i] - bitter_path_sum[i]);
        if (t < div)
        {
            div = t;
        }
    }

    cout << div << '\n';
}
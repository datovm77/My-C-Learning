// P1706 全排列问题
#include <iostream>
#include <vector>
using namespace std;

int n;

vector<int> path;
vector<int> used;

void dfs()
{
    // 已经选够 n 个数字，得到一个排列
    if ((int)path.size() == n)
    {
        for (int x : path)
            cout << x << " ";

        cout << '\n';
        return;
    }

    // 枚举当前位置可以选择的数字
    for (int i = 1; i <= n; i++)
    {
        // 当前排列已经使用过这个数字
        if (used[i])
            continue;

        // 1. 做出选择
        used[i] = 1;
        path.push_back(i);

        // 2. 继续搜索下一个位置
        dfs();

        // 3. 撤销选择
        path.pop_back();
        used[i] = 0;
    }
}

int main()
{
    cin >> n;

    used.resize(n + 1, 0);

    dfs();

    return 0;
}
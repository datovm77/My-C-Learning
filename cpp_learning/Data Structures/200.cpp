// P2089 烤鸡
#include <iostream>
#include <vector>
using namespace std;

int n;
vector<int> path;
vector<vector<int>> paths;

void dfs(int sum, int k)
{
    int rest = 10 - k;

    if (sum + rest > n ||
        sum + 3 * rest < n)
    {
        return;
    }
    if (k == 10)
    {
        if (sum == n)
            paths.push_back(path);
        return;
    }

    for (int i = 1; i <= 3; i++)
    {
        path.push_back(i);
        dfs(sum + i, k + 1);
        path.pop_back();
    }
}

int main()
{
    cin >> n;

    dfs(0, 0);

    cout << paths.size() << '\n';

    for (const auto &p : paths)
    {
        for (int i = 0; i < 10; i++)
        {
            if (i > 0)
                cout << ' ';
            cout << p[i];
        }
        cout << '\n';
    }

    return 0;
}

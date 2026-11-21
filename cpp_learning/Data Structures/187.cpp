// P1157 组合的输出
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
int n, r;
vector<int> path;
void dfs(int start)
{
    if (path.size() == r)
    {
        for (const int &x : path)
        {
            cout << setw(3) << x;
        }
        cout << '\n';
        return;
    }

    for (int i = start; i <= n; i++)
    {
        path.push_back(i);
        dfs(i + 1);
        path.pop_back();
    }
}

int main()
{
    cin >> n >> r;
    dfs(1);
    return 0;
}
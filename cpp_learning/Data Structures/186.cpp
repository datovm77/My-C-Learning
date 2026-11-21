// P1706 全排列问题
#include <iostream>
#include <vector>

using namespace std;
vector<int> usd;
vector<int> path;
int n;
void DFS()
{
    if (path.size() == n)
    {
        for (const int &xx : path)
        {
            cout << "    " << xx;
        }
        cout << '\n';
    }
    for (int i = 1; i <= n; i++)
    {
        if (usd[i] == 1)
        {
            continue;
        }
        path.push_back(i);
        usd[i] = 1;
        DFS();
        path.pop_back();
        usd[i] = 0;
    }
}

int main()
{

    cin >> n;
    usd.assign(n, 0);
    DFS();

    return 0;
}
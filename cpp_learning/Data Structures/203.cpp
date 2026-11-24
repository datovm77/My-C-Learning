// P2404 自然数的拆分问题
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int n;
vector<int> path;
void dfs(int start, int remain)
{
    if (remain == 0)
    {
        if (path.size() >= 2)
        {
            for (int i = 0; i < (int)path.size(); i++)
            {
                if (i > 0)
                    cout << "+";
                cout << path[i];
            }
            cout << '\n';
        }
        return;
    }

    for (int i = start; i <= remain; i++)
    {
        path.push_back(i);
        dfs(i, remain - i);
        path.pop_back();
    }
}
int main()
{
    cin >> n;
    dfs(1, n);

    return 0;
}
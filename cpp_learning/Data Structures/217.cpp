// P1873 砍树
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> tree;
int n, m;
bool check(int h)
{
    int sum = 0;
    for (const int &x : tree)
    {
        int cut = max(0, x - h);
        sum += cut;
        if (sum >= m)
            return true;
    }
    return false;
}

int main()
{

    cin >> n >> m;
    tree.resize(n);
    int tree_max = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> tree[i];
        tree_max = max(tree_max, tree[i]);
    }
    int l = 1;
    int r = tree_max;
    int ans = -1;
    while (l <= r)
    {
        int mid = l + (r - l + 1) / 2;
        if (check(mid))
        {
            ans = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }

    cout << ans << '\n';
}

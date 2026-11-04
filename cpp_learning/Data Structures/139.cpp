#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Milk
{
    int price;
    int amount;
};

int main()
{
    int n, m;
    cin >> n >> m;

    vector<Milk> v(m);

    for (int i = 0; i < m; i++)
    {
        cin >> v[i].price >> v[i].amount;
    }

    // 按单价从小到大排序
    sort(v.begin(), v.end(), [](const Milk &a, const Milk &b)
         { return a.price < b.price; });

    long long cost = 0;

    for (int i = 0; i < m && n > 0; i++)
    {
        // 当前农民最多能卖多少，就买多少
        // 但不能超过我们还需要的数量
        int buy = min(n, v[i].amount);

        cost += 1LL * buy * v[i].price;
        n -= buy;
    }

    cout << cost << '\n';

    return 0;
}

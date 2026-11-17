// P8681 完全二叉树的权值
#include <iostream>
#include <queue>
#include <vector>
#include <unordered_map>
using namespace std;
int main()
{
    int N;
    if (!(std::cin >> N))
        return 0;

    vector<int> v(N + 1, 0);
    queue<int> q;
    for (int j = 1; j <= N; j++)
    {
        cin >> v[j];
    }

    q.push(1);
    int dep = 1;
    long long max_sum = -1;
    int ans = 1;
    while (!q.empty())
    {
        int sz = (int)q.size();
        long long sum = 0;
        for (int i = 0; i < sz; i++)
        {
            int u = q.front();
            q.pop();

            sum += v[u];

            if (2 * u <= N)
            {
                q.push(2 * u);
            }
            if (2 * u + 1 <= N)
            {
                q.push(2 * u + 1);
            }
        }
        if (sum > max_sum)
        {
            max_sum = sum;
            ans = dep;
        }
        dep++;
    }
    cout << ans << '\n';
}
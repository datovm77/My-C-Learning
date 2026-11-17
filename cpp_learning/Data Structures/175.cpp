// P1588 Catch That Cow S
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int t;
    if (!(cin >> t))
        return 0;
    while (t--)
    {
        queue<int> q;
        vector<int> v;
        int x, y;
        cin >> x >> y;
        q.push(x);
        v.assign(100001, -1);
        v[x] = 0;
        while (!q.empty())
        {
            int xx = q.front();
            if (xx == y)
            {
                break;
            }
            int dx[] = {xx + 1, xx - 1, 2 * xx};
            for (int i = 0; i < 3; i++)
            {
                int nx = dx[i];
                if (nx <= 0 || nx > 100000 || v[nx] != -1)
                {
                    continue;
                }
                q.push(nx);
                v[nx] = v[xx] + 1;
            }
            q.pop();
        }
        std::cout << v[y] << '\n';
    }
}
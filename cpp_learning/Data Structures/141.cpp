// P1803 凌乱的yyy / 线段覆盖
#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
struct t_lr
{
    /* data */
    int l;
    int r;
};

int main()
{
    int n;
    if (!(std::cin >> n))
        return 0;
    std::vector<t_lr> v;
    for (int i = 0; i < n; i++)
    {
        t_lr t;
        std::cin >> t.l >> t.r;
        v.push_back(t);
    }
    std::sort(v.begin(), v.end(), [](const t_lr &t1, const t_lr &t2)
              {
        if(t1.r != t2.r)
        {
            return t1.r<t2.r;
        }
        return t1.l <t2.l; });

    int ans = 0;
    int last_end = INT_MIN;
    for (const auto &x : v)
    {
        if (x.l >= last_end)
        {
            ans++;
            last_end = x.r;
        }
    }
    std::cout << ans << '\n';

    return 0;
}

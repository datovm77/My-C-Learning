#include <iostream>

static int a[1000005];

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, m;
    std::cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        std::cin >> a[i];

    while (m--)
    {
        int q;
        std::cin >> q;

        int ans = -1;
        for (int i = 1; i <= n; ++i)
        {
            if (a[i] == q)
            {
                ans = i;
                break;
            }
            if (a[i] > q)
                break;
        }
        std::cout << ans << ' ';
    }

    return 0;
}

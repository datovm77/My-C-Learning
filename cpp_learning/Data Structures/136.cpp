#include <iostream>
#include <vector>

bool check(std::vector<int> v, int gap_min, int M)
{
    int count = 0;
    for (int i = 1; i < static_cast<int>(v.size()); i++)
    {
        int gap = v[i] - v[i - 1];
        if (gap < gap_min)
        {
            count++;
            v[i] = v[i - 1];
        }
        if (count > M)
            return false;
    }
    return true;
}

int main()
{
    int L, N, M;
    if (!(std::cin >> L >> N >> M))
        return 0;
    std::vector<int> v(N + 2, 0);
    for (int i = 1; i <= N; i++)
    {
        std::cin >> v[i];
    }
    v[N + 1] = L;
    int l = 1;
    int r = L;

    int ans = 0;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (check(v, mid, M))
        {
            l = mid + 1;
            ans = mid;
        }
        else
            r = mid - 1;
    }
    std::cout << ans << '\n';
}
#include <iostream>
#include <vector>
using namespace std;

bool check(const vector<int> &v, int gap_min, int M)
{
    int count = 0;
    int last = 0;

    for (int i = 1; i < (int)v.size(); i++)
    {
        if (v[i] - last < gap_min)
        {
            count++;
        }
        else
        {
            last = v[i];
        }

        if (count > M)
            return false;
    }

    return true;
}

int main()
{
    int L, N, M;
    cin >> L >> N >> M;

    vector<int> v(N + 2, 0);

    for (int i = 1; i <= N; i++)
        cin >> v[i];

    v[N + 1] = L;

    int l = 1, r = L;
    int ans = 0;

    while (l <= r)
    {
        int mid = l + (r - l) / 2;

        if (check(v, mid, M))
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

    return 0;
}
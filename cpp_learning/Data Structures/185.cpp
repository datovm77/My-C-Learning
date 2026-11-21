// CSP202603A 平衡数
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    int count = 0;
    for (const int &x : v)
    {
        int n = 0;
        int ans = 0;
        while (1)
        {
            long long num_big = 1LL << (n + 1); // 原：1 << (n + 1)
            long long num_small = 1LL << n;     // 原：1 << (n)

            if (x >= num_small && x < num_big)
            {
                ans = n + 1;
                break;
            }
            n++;
        }
        if ((ans & 1) != 0)
        {
            continue;
        }
        int cal_x = x;
        int one_num = 0;
        while (cal_x != 0)
        {
            cal_x &= cal_x - 1;
            one_num++;
        }
        if (ans / 2 == one_num)
        {
            count++;
        }
    }

    cout << count << '\n';
}

// CSP202312B 因子化简
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;

    while (q--)
    {
        long long n, k;
        cin >> n >> k;

        long long ans = 1;

        for (long long p = 2; p * p <= n; p++)
        {
            int count = 0;
            long long factor = 1;

            while (n % p == 0)
            {
                n /= p;
                factor *= p;
                count++;
            }

            if (count >= k)
            {
                ans *= factor;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}
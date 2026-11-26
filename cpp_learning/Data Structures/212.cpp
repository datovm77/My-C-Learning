// CSP202312B 因子化简
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int main()
{
    int q;
    cin >> q;

    vector<int> primes;
    vector<bool> isPrime(100001, true);
    isPrime[0] = false;
    isPrime[1] = false;

    for (int i = 2; i <= 100000 / i; ++i)
    {
        if (isPrime[i])
        {
            for (long long j = 1LL * i * i; j <= 100000; j += i)
            {
                isPrime[j] = false;
            }
        }
    }
    for (int i = 0; i <= 100000; i++)
    {
        if (isPrime[i])
            primes.push_back(i);
    }

    while (q--)
    {
        long long n, k;
        cin >> n >> k;

        long long ans = 1;

        for (int p : primes)
        {
            if (1LL * p * p > n)
                break;

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
// P1036 选数
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n, k;
int sum_prime = 0;
vector<int> path;
vector<int> num;
bool if_prime(int number)
{
    if (number < 2)
        return false;
    if (number == 2 || number == 3)
        return true;
    if (number % 2 == 0 || number % 3 == 0)
        return false;
    for (int i = 5; i <= number / i; i += 6)
    {
        if ((number % i == 0) || (number % (i + 2) == 0))
            return false;
    }
    return true;
}

// bool if_prime_must_rem(int m)
// {
//     if (m < 2)
//         return false;
//     for (int i = 2; i <= n / i; i++)
//     {
//         if (n % i == 0)
//         {
//             return false;
//         }
//     }
//     return true;
// }

// 存储1-m的所有素数
// void sieve(int m)
// {
//     // 先假设所有都是素数，然后一个个排除
//     vector<bool> isPrime(m + 1, true);
//     isPrime[0] = false;
//     if (n >= 1)
//         isPrime[1] = false;
//     for (int i = 2; 1LL * i * i <= n; i++)
//     {
//         // 如果已经被排除那就跳过
//         if (!isPrime[i])
//             continue;
//         for (long long j = 1LL * i * i; j <= n; j += i)
//         {
//             isPrime[(int)j] = false;
//         }
//     }
// }

void dfs(int start)
{
    if (k == path.size())
    {
        int sum = 0;
        for (const int &x : path)
        {
            sum += x;
        }
        if (if_prime(sum))
            sum_prime++;
        return;
    }
    for (int i = start; i < n; i++)
    {
        path.push_back(num[i]);
        dfs(i + 1);
        path.pop_back();
    }
}

int main()
{
    cin >> n >> k;
    num.resize(n);
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    sort(num.begin(), num.end());
    dfs(0);
    cout << sum_prime << '\n';
}
// P8681 完全二叉树的权值
#include <iostream>
// #include <vector>
#include <climits>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int count_t = 1;
    int count = 0;
    long long sum = 0;
    // long long sum_max = -1LL >> 60;
    long long sum_max = LLONG_MIN;
    int ans = 0;
    int dep = 1;
    for (int i = 0; i < n; i++)
    {
        int number;
        cin >> number;
        sum += number;
        count++;
        if (count == count_t || i == n - 1)
        {
            if (sum > sum_max)
            {
                sum_max = sum;
                ans = dep;
            }
            sum = 0;
            count = 0;
            count_t *= 2;
            dep++;
        }
    }
    std::cout << ans << '\n';
}

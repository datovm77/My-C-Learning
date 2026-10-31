#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int minSubArrayLen(int target, const vector<int> &a)
{
    int n = a.size();

    int left = 0;
    long long sum = 0;

    int ans = n + 1;

    for (int right = 0; right < n; right++)
    {

        // 第一步：扩大窗口
        sum += a[right];

        // 第二步：窗口满足条件，尝试缩小
        while (sum >= target)
        {

            // 更新最短长度
            ans = min(ans, right - left + 1);

            // 移除左端元素
            sum -= a[left];

            // 左指针右移
            left++;
        }
    }

    if (ans == n + 1)
    {
        return 0; // 没有满足条件的窗口
    }

    return ans;
}

int main()
{
    int n, target;
    cin >> n >> target;

    vector<int> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << minSubArrayLen(target, a) << '\n';

    return 0;
}
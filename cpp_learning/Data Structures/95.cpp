#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr); // 解除 cin 与 cout 的绑定，减少大量输入时自动刷新输出的开销。

    int n, p;
    if (!(std::cin >> n >> p))
        return 0;

    // div 改名为 diff，更明确地表示差分数组；n + 2 保证 y == n 时 diff[y + 1] 不越界。
    std::vector<int> diff(n + 2, 0);
    int previous = 0;
    // 读入时直接构造差分，只需保存前一个成绩，省去 first 数组及其扩容开销。
    for (int i = 1; i <= n; i++)
    {
        int number;
        std::cin >> number;
        diff[i] = number - previous;
        previous = number;
    }

    while (p--)
    {
        int x, y, z;
        std::cin >> x >> y >> z;
        diff[x] += z;
        diff[y + 1] -= z;
    }
    int score = 0;
    int minimum = std::numeric_limits<int>::max(); // 用 int 最大值初始化，避免第一次比较遗漏最低分。
    // 累加差分还原成绩时同步求最低分，省去存回 first 和 min_element 的额外遍历。
    for (int i = 1; i <= n; i++)
    {
        score += diff[i];
        minimum = std::min(minimum, score);
    }

    std::cout << minimum << '\n';
}

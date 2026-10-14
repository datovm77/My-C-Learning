#include <iostream>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(0);
    int n, p;
    std::cin >> n >> p;
    std::vector<int> s(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        int student;
        std::cin >> student;
        s.push_back(student);
    }

    std::vector<int> d(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        d[i] = s[i] - s[i - 1];
    }
    while (p--)
    {
        int x, y, z;
        std::cin >> x >> y >> z;
        d[x] += z;
        d[y + 1] -= z;
    }

    for (int i = 1; i <= n; i++)
    {
    }
}
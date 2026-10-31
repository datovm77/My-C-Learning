#include <iostream>
#include <string>
#include <vector>

void preorder(const std::vector<int> &v1, int index)
{
    if (v1[index] == 0 || index >= static_cast<int>(v1.size()))
        return;
    std::cout << v1[index] << ' ';
    preorder(v1, 2 * index);
    preorder(v1, 2 * index + 1);
}

int main()
{
    std::ios::sync_with_stdio(0);
    int t;
    if (!(std::cin >> t))
        return 0;
    while (t--)
    {
        int n;
        std::cin >> n;
        std::vector<int> v(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            std::cin >> v[i];
        }
        int index = 1;
        preorder(v, index);
        std::cout << '\n';
    }
}
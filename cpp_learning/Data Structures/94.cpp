#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::ios::sync_with_stdio(0);
    int n;
    if (!(std::cin >> n))
        return 0;

    while (n--)
    {
        std::string s;
        std::cin >> s;

        int n = s.size();

        std::vector<int> next(n + 1);

        int i = 0;
        int j = -1;
        next[0] = -1;

        while (i < n)
        {
            if (j == -1 || s[i] == s[j])
            {
                j++;
                i++;
                next[i] = j;
            }
            else
                j = next[j];
        }

        int p = n - next[n];

        int ans;

        if (p == n)
        {
            ans = n;
        }
        else
            ans = (p - n % p) % p;

        std::cout << ans << '\n';
    }

    return 0;
}
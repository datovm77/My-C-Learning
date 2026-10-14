#include <iostream>
#include <string>

int main()
{
    int t;
    if (!(std::cin >> t))
        return 0;
    while (t--)
    {
        int count = 0;
        int max_count = 0;
        std::string s;
        std::cin >> s;
        int len = static_cast<int>(s.size());
        for (int i = 0; i < len; i++)
        {
            for (int j = i + 1; j < len; j++)
            {
                int ii = i;
                int jj = j;
                while (ii < j && jj < len && s[ii] == s[jj]) // while (s[ii] == s[jj])
                {
                    ii++;
                    jj++;
                    count++;
                }
                if (count > max_count) // if ((count > max_count) && (count <= (len / 2)))
                    max_count = count;
                count = 0;
            }
        }
        if (max_count)
            std::cout << max_count << '\n';
        else
            std::cout << -1 << '\n';
    }

    return 0;
}

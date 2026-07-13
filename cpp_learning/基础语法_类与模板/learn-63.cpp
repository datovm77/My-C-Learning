#include <iostream>
#include <string>
#include <vector>

template <typename T>
void elect(const std::vector<T> &votes)
{
    T winner = votes[0];
    int max_count = 0;

    for (size_t i = 0; i < votes.size(); ++i)
    {
        int count = 0;
        for (size_t j = 0; j < votes.size(); ++j)
        {
            if (votes[i] == votes[j])
            {
                ++count;
            }
        }

        if (count > max_count)
        {
            max_count = count;
            winner = votes[i];
        }
    }

    std::cout << winner << ' ' << max_count << '\n';
}

int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        char type;
        int n;
        std::cin >> type >> n;

        if (type == 'I')
        {
            std::vector<int> votes(n);
            for (int i = 0; i < n; ++i)
            {
                std::cin >> votes[i];
            }
            elect(votes);
        }
        else if (type == 'C')
        {
            std::vector<char> votes(n);
            for (int i = 0; i < n; ++i)
            {
                std::cin >> votes[i];
            }
            elect(votes);
        }
        else if (type == 'S')
        {
            std::vector<std::string> votes(n);
            for (int i = 0; i < n; ++i)
            {
                std::cin >> votes[i];
            }
            elect(votes);
        }
    }

    return 0;
}

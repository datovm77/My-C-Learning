#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
template <typename T>
void my_check(const std::vector<T> &arr)
{
    std::unordered_map<T, int> mp;
    for (size_t i = 0; i < arr.size(); ++i)
    {
        mp[arr[i]]++;
    }

    int max = 0;
    T values;
    for (const auto &[value, time] : mp)
    {
        if (time >= max)
        {
            max = time;
            values = value;
        }
    }
    std::cout << values << ' ' << max << '\n';
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
            std::vector<int> arr(n);
            for (int i = 0; i < n; ++i)
            {
                std::cin >> arr[i];
            }

            my_check(arr);
        }
        else if (type == 'C')
        {
            std::vector<char> arr(n);
            for (int i = 0; i < n; ++i)
            {
                std::cin >> arr[i];
            }

            my_check(arr);
        }
        else if (type == 'S')
        {
            std::vector<std::string> arr(n);
            for (int i = 0; i < n; ++i)
            {
                std::cin >> arr[i];
            }

            my_check(arr);
        }
    }

    return 0;
}

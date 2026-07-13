#include <iostream>
#include <string>
#include <vector>

template <typename T>
int m_find(const std::vector<T> &arr, const T &key)
{
    for (size_t i = 0; i < arr.size(); ++i)
    {
        if (arr[i] == key)
        {
            return static_cast<int>(i + 1);
        }
    }
    return 0;
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
            int key;
            std::cin >> key;
            std::cout << m_find(arr, key) << '\n';
        }
        else if (type == 'D')
        {
            std::vector<double> arr(n);
            for (int i = 0; i < n; ++i)
            {
                std::cin >> arr[i];
            }
            double key;
            std::cin >> key;
            std::cout << m_find(arr, key) << '\n';
        }
        else if (type == 'C')
        {
            std::vector<char> arr(n);
            for (int i = 0; i < n; ++i)
            {
                std::cin >> arr[i];
            }
            char key;
            std::cin >> key;
            std::cout << m_find(arr, key) << '\n';
        }
        else if (type == 'S')
        {
            std::vector<std::string> arr(n);
            for (int i = 0; i < n; ++i)
            {
                std::cin >> arr[i];
            }
            std::string key;
            std::cin >> key;
            std::cout << m_find(arr, key) << '\n';
        }
    }

    return 0;
}

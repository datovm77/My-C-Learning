#include <iostream>

int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        int n;
        std::cin >> n;

        int arr[n];
        for (int i = 0; i < n; i++)
        {
            int number;
            std::cin >> number;
            arr[i] = number;
        }

        int *p = arr + n / 2;

        --p;
        std::cout << *p << " ";
        ++p;
        ++p;
        std::cout << *p << '\n';
        --p;

        int num;
        std::cin >> num;
        int dist = num - 1 - n / 2;
        p += dist;
        std::cout << *p << '\n';
    }
}

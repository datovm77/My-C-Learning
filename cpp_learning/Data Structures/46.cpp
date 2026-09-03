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
        int middle = n / 2;
        // std::cout << n << '\n';
        int qian = --middle;
        ++middle;
        int hou = ++middle;
        std::cout << *(arr + qian) << " " << *(arr + hou) << '\n';
        int num;
        std::cin >> num;
        std::cout << *(arr + num - 1) << '\n';
    }
}
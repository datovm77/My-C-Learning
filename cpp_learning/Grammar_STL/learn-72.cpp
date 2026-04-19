#include <iostream>
int main()
{
    int arr[5] = {2, 4, 6, 8, 10};
    for (int i = 0; i < 5; i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';

    for (int i = 0; i < 5; i++)
    {
        std::cout << i[arr] << ' ';
    }
    std::cout << '\n';

    for (int i = 0; i < 5; i++)
    {
        std::cout << *(arr + i) << ' ';
    }
    std::cout << '\n';
    return 0;
}
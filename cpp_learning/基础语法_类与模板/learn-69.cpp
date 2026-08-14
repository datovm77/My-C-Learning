#include <iostream>

int main()
{
    int arr[] = {1, 5, 3, 8, 21, 5, 12, 4, 331, 1, 254};
    for (auto &it : arr)
    {
        std::cout << it << ' ';
    }
    std::cout << "\n";
}
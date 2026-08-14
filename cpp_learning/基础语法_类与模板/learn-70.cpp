#include <algorithm>
#include <cstddef>
#include <functional>
#include <iostream>
#include <iterator>
#include <numeric>
#include <string>
#include <vector>

template <class Container>
void print(const Container &values)
{
    for (const auto &value : values)
    {
        std::cout << value << ' ';
    }
    std::cout << '\n';
}

int main()
{
    int arr[] = {3, 1, 5, 2, 4};
    // std::sort(std::begin(arr), std::end(arr), std::greater<int>());
    std::sort(arr, arr + (sizeof(arr) / sizeof(int)), std::greater<int>());
    print(arr);
}
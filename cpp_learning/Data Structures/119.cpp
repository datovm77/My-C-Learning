#include <iostream>

int bsearch(int *arr, int size, int target)
{
    int left = 1;
    int right = size;
    int ans = -1;
    while (left <= right)
    {
        int middle = left + (right - left) / 2;

        if (arr[middle] >= target)
        {
            if (arr[middle] == target)
                ans = middle;
            right = middle - 1;
        }
        else
            left = middle + 1;
    }
    return ans;
}

int main()
{
    std::ios::sync_with_stdio(0);
    int n, m;
    if (!(std::cin >> n >> m))
        return 0;

    int *arr = new int[n + 1];
    for (int i = 1; i <= n; i++)
    {
        std::cin >> arr[i];
    }
    while (m--)
    {
        int target;
        std::cin >> target;
        int result = bsearch(arr, n, target);
        std::cout << result << ' ';
    }

    delete[] arr;
    return 0;
}
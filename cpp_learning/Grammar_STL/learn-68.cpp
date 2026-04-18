#include <iostream>

int arr[15] = {-1};

int mfib(int n)
{
    if (n <= 1)
        return n;

    if (arr[n - 2] == -1)
    {
        arr[n - 2] = mfib(n - 2);
    }
    else if (arr[n - 1] == -1)
    {
        arr[n - 1] = mfib(n - 1);
    }

    return mfib(n - 2) + mfib(n - 1);
}


//test
int main()
{
    int r = 7;
    std::cout << mfib(r) << '\n';
    return 0;
}

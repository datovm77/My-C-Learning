#include <iostream>

int main()
{
    int *p = new int[5];
    for (int i = 0; i < 5; i++)
    {
        std::cin >> p[i];
    }

    for (int i = 0; i < 5; i++)
    {
        std::cout << p[i] << ' ';
    }
    std::cout << '\n';

    int *q = new int[10]{};
    for (int i = 0; i < 5; ++i)
    {
        q[i] = p[i];
    }
    delete[] p;

    p = q;
    q = nullptr;

    for (int i = 0; i < 10; i++)
    {
        std::cout << p[i] << ' ';
    }
    std::cout << '\n';
    delete[] p;
    return 0;
}

// P1029 [NOIP 2001 普及组] 最大公约数和最小公倍数问题
#include <iostream>

int GCD(int a, int b)
{
    while (b != 0)
    {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

int LCM(int a, int b)
{
    return a / GCD(a, b) * b;
}

int main()
{
    int x, y;
    if (!(std::cin >> x >> y))
        return 0;

    int count = 0;
    long long product = 1LL * x * y;
    for (int i = x; i <= y; i++)
    {
        if (product % i != 0)
            continue;

        int j = static_cast<int>(product / i);
        if ((GCD(i, j) == x) && (LCM(i, j) == y))
        {
            count++;
        }
    }
    std::cout << count << '\n';
    return 0;
}

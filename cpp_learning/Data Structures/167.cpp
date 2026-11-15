// P1010 [NOIP 1998 普及组] 幂次方
#include <iostream>

void print(int n)
{
    bool first = true;

    for (int start = 15; start >= 0; start--)
    {
        if (n / (1 << start) == 1)
        {
            if (!first)
            {
                std::cout << '+';
            }
            first = false;
            if (start == 0)
            {
                std::cout << "2(0)";
            }
            else if (start == 1)
            {
                std::cout << "2";
            }
            else
            {
                std::cout << "2(";
                print(start);
                std::cout << ")";
            }

            n %= (1 << start);
        }
    }
}

int main()
{
    int n;
    if (!(std::cin >> n))
        return 0;
    print(n);
    return 0;
}
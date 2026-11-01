// P1147 连续正整数和
#include <iostream>
#include <vector>

int main()
{
    int M;
    if (!(std::cin >> M))
        return 0;

    int sum = 0;

    int begin = 1;
    for (int i = 1; i <= ((M + 1) / 2); i++)
    {
        sum += i;
        while (sum > M)
        {
            sum -= begin;
            begin++;
        }
        if (sum == M)
        {
            std::cout << begin << ' ' << i << '\n';
        }
    }
}

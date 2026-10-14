#include <iostream>

int num(int buy)
{
    int sum = buy;
    while ((buy / 3) != 0)
    {
        sum += (buy / 3);
        buy = (buy / 3) + (buy % 3);
    }
    return sum;
}

int main()
{
    std::ios::sync_with_stdio(0);
    int buy_num;
    std::cin >> buy_num;
    int number = num(buy_num);
    std::cout << number << '\n';
}
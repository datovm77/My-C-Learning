#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
struct gold_coin
{
    /* data */
    int weight;
    int value;
    double u_price;
};

int main()
{
    int N, T;
    if (!(std::cin >> N >> T))
        return 0;

    std::vector<gold_coin> v;
    for (int i = 0; i < N; i++)
    {
        gold_coin g1;
        std::cin >> g1.weight >> g1.value;
        g1.u_price = g1.value * 1.0 / g1.weight;
        v.push_back(g1);
    }

    std::sort(v.begin(), v.end(), [](const gold_coin &g1, const gold_coin &g2)
              {
        if(g1.u_price != g2.u_price)
        {
            return g2.u_price<g1.u_price;
        }
        return g2.weight < g1.weight; });

    double sum_value = 0;
    int T_rest = T;
    for (int i = 0; i < N && T_rest > 0; i++)
    {
        int weight = std::min(T_rest, v[i].weight);
        sum_value += 1.00 * (weight * v[i].u_price);
        T_rest -= weight;
    }
    std::cout << std::fixed << std::setprecision(2) << sum_value << '\n';
}
#include <iostream>

class metal
{
private:
    int hard;
    int weight;
    int v;

public:
    metal(const int &hard, const int weight, const int &v) : hard(hard), weight(weight), v(v) {}

    friend metal operator+(const metal &m1, const metal &m2);
    friend metal operator*(const metal &m1, int n);

    metal &operator++()
    {
        hard++;
        weight *= 1.1;
        v *= 1.1;
        return *this;
    }
    metal operator--(int)
    {
        int hard_old = hard;
        int weight_old = weight;
        int v_old = v;

        hard--;
        weight *= 0.9;
        v *= 0.9;

        return metal(hard_old, weight_old, v_old);
    }

    void print_metal()
    {
        std::cout << "硬度" << hard << "--" << "重量" << weight << "--" << "体积" << v << '\n';
    }
};

metal operator+(const metal &m1, const metal &m2)
{
    return metal(m1.hard + m2.hard, m1.weight + m2.weight, m1.v + m2.v);
}
metal operator*(const metal &m1, int n)
{
    return metal(m1.hard, m1.weight, m1.v * n);
}

int main()
{
    int hard1, weight1, v1;
    int hard2, weight2, v2;

    std::cin >> hard1 >> weight1 >> v1;
    std::cin >> hard2 >> weight2 >> v2;

    int huge_times;
    std::cin >> huge_times;

    metal finish_hebing = metal(hard1, weight1, v1) + metal(hard2, weight2, v2);
    finish_hebing.print_metal();
    metal m1 = metal(hard1, weight1, v1);

    metal m1_huge = m1 * huge_times;
    m1_huge.print_metal();

    metal m1_hard = ++m1;
    m1_hard.print_metal();

    metal m2 = metal(hard2, weight2, v2);
    m2--;
    m2.print_metal();
}
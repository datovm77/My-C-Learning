// 练习unique_ptr管理int和char动态数组的输入计算
#include <iostream>
#include <string>
#include <memory>

void test_I(int num)
{
    auto group = std::make_unique<int[]>(num);
    int *base = group.get();

    for (int i = 0; i < num; ++i)
    {
        std::cin >> *(base + i);
    }
    int sum = 0;
    for (int i = 0; i < num; ++i)
    {
        sum += *(base + i);
    }
    int result = sum / num;
    std::cout << result << '\n';
}

void test_C(int num)
{
    auto group = std::make_unique<char[]>(num);
    char *base = group.get();
    char max = 'A';
    for (int i = 0; i < num; ++i)
    {
        std::cin >> *(base + i);
        if (*(base + i) > max)
        {
            max = *(base + i);
        }
    }
    std::cout << max << '\n';
}

void test_F(int num)
{
    auto group = std::make_unique<double[]>(num);
    double *base = group.get();
    double min = 10000.0;
    for (int i = 0; i < num; ++i)
    {
        std::cin >> *(base + i);
        if (*(base + i) < min)
        {
            min = *(base + i);
        }
    }
    std::cout << min << '\n';
}

int main()
{
    int n;
    std::cin >> n;

    while (n--)
    {
        char type;
        int num;
        std::cin >> type >> num;
        switch (type)
        {
        case 'I':
            test_I(num);
            break;
        case 'C':
            test_C(num);
            break;
        case 'F':
            test_F(num);
            break;

        default:
            break;
        }
    }

    return 0;
}
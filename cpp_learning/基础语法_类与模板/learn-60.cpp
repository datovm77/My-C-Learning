#include <iostream>
#include <string>

template <typename T>
int m_find(T arr[], int length, T key)
{
    for (int i = 0; i < length; i++)
    {
        if (arr[i] == key)
        {
            return i + 1;
        }
    }
    return 0;
}

int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        char type;
        std::cin >> type;

        int num;
        std::cin >> num;

        if (type == 'I') // 整数
        {
            int arr[num];
            for (int i = 0; i < num; i++)
            {
                int zhi;
                std::cin >> zhi;
                arr[i] = zhi;
            }
            int key;
            std::cin >> key;
            std::cout << m_find(arr, num, key) << '\n';
        }
        else if (type == 'D') // 双精度数类型
        {
            double arr[num];
            for (int i = 0; i < num; i++)
            {
                double zhi;
                std::cin >> zhi;
                arr[i] = zhi;
            }
            double key;
            std::cin >> key;
            std::cout << m_find(arr, num, key) << '\n';
        }
        else if (type == 'C') // 字符类型
        {
            char arr[num];
            for (int i = 0; i < num; i++)
            {
                char zhi;
                std::cin >> zhi;
                arr[i] = zhi;
            }
            char key;
            std::cin >> key;
            std::cout << m_find(arr, num, key) << '\n';
        }
        else if (type == 'S') // 字符串类型
        {
            std::string arr[num];
            for (int i = 0; i < num; i++)
            {
                std::string zhi;
                std::cin >> zhi;
                arr[i] = zhi;
            }
            std::string key;
            std::cin >> key;
            std::cout << m_find(arr, num, key) << '\n';
        }
    }
}
// 练习动态二维数组的矩阵转置与指针操作
#include <iostream>
#include <string>
#include <vector>

void test01()
{


    int t;
    std::cin >> t;

    for (int m = 0; m < t; ++m)
    {
        int (*p)[3] = new int[2][3];
        int (*p1)[2] = new int[3][2];

        for (int i = 0; i < 2; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                int temp;
                std::cin >> temp;
                p[i][j] = temp;
            }
        }

        for (int i = 0; i < 2; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                p1[2 - j][i] = p[i][j];
            }
        }

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                std::cout << p1[i][j]<<' ';
            }
            std::cout << '\n';
        }
    }
}

int main()
{
    test01();

    return 0;
}
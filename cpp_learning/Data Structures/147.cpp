// [蓝桥杯 2020 省 B] 蛇形填数
#include <iostream>
using namespace std;

int main()
{
    int number = 1;
    int ans = 0;

    for (int sum = 2; sum <= 40; sum++)
    {

        if (sum % 2 == 1)
        {
            // 从上往下
            for (int row = 1; row < sum; row++)
            {
                int col = sum - row;

                if (row == 20 && col == 20)
                    ans = number;

                number++;
            }
        }
        else
        {
            // 从下往上
            for (int row = sum - 1; row >= 1; row--)
            {
                int col = sum - row;

                if (row == 20 && col == 20)
                    ans = number;

                number++;
            }
        }
    }

    cout << ans; // 761
    return 0;
}
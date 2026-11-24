// P1618 三连击（升级版）
#include <iostream>
#include <vector>
using namespace std;

// 判断三个数是否恰好包含 1~9
bool check(int x, int y, int z)
{
    vector<int> vis(10, 0);
    int nums[3] = {x, y, z};

    for (int num : nums)
    {
        while (num > 0)
        {
            int digit = num % 10;

            // 不能出现 0，也不能重复
            if (digit == 0 || vis[digit])
                return false;

            vis[digit] = 1;
            num /= 10;
        }
    }

    return true;
}

int main()
{
    int A, B, C;
    cin >> A >> B >> C;

    if (A == 0)
    {
        cout << "No!!!\n";
        return 0;
    }

    bool found = false;

    for (int x = 123; x <= 999; x++)
    {
        // y、z 必须是整数
        if (x * B % A != 0 || x * C % A != 0)
            continue;

        int y = x * B / A;
        int z = x * C / A;

        // 必须都是三位数
        if (y > 999 || z > 999)
            continue;

        if (check(x, y, z))
        {
            cout << x << " " << y << " " << z << '\n';
            found = true;
        }
    }

    if (!found)
        cout << "No!!!\n";

    return 0;
}

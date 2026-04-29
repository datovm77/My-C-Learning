// 练习汉诺塔递归算法，std::format格式化输出移动步骤
#include <iostream>
#include <format>
#include <string>
void hannuotower(int n, char A, char B, char C)
{
    if (n > 0)
    {
        hannuotower(n - 1, A, C, B);
        std::cout << std::format("from {} to {}", A, C) << '\n';
        hannuotower(n - 1, B, A, C);
    }
}

int main()
{
    int r = 3;
    hannuotower(r, 'A', 'B', 'C');

    return 0;
}

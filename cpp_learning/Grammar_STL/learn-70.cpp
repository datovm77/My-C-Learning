#include <iostream>
using namespace std;

// 递归版
int sumRecursive(int n)
{
    if (n == 0)
        return 0;                   // 基线条件
    return sumRecursive(n - 1) + n; // 递归条件
}

// 迭代版（对比）
int sumIterative(int n)
{
    int total = 0;
    for (int i = 1; i <= n; i++)
        total += i;
    return total;
}

// 公式法（对比）
int sumFormula(int n)
{
    return n * (n + 1) / 2;
}

int main()
{
    int n = 10;
    cout << "递归: " << sumRecursive(n) << endl; // 55
    cout << "迭代: " << sumIterative(n) << endl; // 55
    cout << "公式: " << sumFormula(n) << endl;   // 55
    return 0;
}
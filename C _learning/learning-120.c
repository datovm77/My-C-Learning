#include <stdio.h>
#include <math.h>

int main() {
    double eps, x;
    // 1. 安全读取输入
    if (scanf("%lf %lf", &eps, &x) != 2) return 0;

    // 2. 初始化变量
    // sum: 累加总和，初始为第一项 (x^0 / 0! = 1)
    // term: 当前项的值，初始为 1
    // x_sq: 预计算 x 的平方，减少循环内的乘法运算
    double sum = 1.0;
    double term = 1.0;
    double x_sq = x * x;
    int n = 1;

    // 3. 核心循环：递推累加
    // 只要当前项的绝对值还大于精度要求，就继续算
    while (fabs(term) > eps) {
        /* 递推公式推导：
           下一项 = 上一项 * (-x^2) / [(2n-1) * 2n]
           n=1 时: term = 1 * (-x^2) / (1*2)  -> 即 -x^2/2!
           n=2 时: term = (-x^2/2!) * (-x^2) / (3*4) -> 即 x^4/4!
        */
        term *= (-x_sq) / ((2 * n - 1) * (2 * n));
        sum += term;
        n++;
    }

    // 4. 格式化输出
    printf("cos(%.2lf) = %.6lf\n", x, sum);

    return 0;
}
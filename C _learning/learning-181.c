//欧拉函数求一个小于n的数与n互质的数字的个数
#include <stdio.h>

/**
 * 使用公式法计算欧拉函数 phi(n)
 * 时间复杂度：O(sqrt(n))，比之前的 O(n log n) 快得多！
 */
long long euler_phi(long long n) {
    long long res = n; // 初始设为 n

    // 从 2 开始找质因数，直到 sqrt(n)
    for (long long i = 2; i * i <= n; i++) {
        // 如果 i 能整除 n，说明 i 是一个质因数
        if (n % i == 0) {
            // 应用公式：res = res * (1 - 1/i) -> 变为整数运算
            res = res / i * (i - 1);

            // 把所有的因子 i 都除掉，确保下次找到的 i 一定是质数
            while (n % i == 0) {
                n /= i;
            }
        }
    }

    // 如果最后 n > 1，说明剩下的 n 本身就是一个大于 sqrt(n) 的质因数
    if (n > 1) {
        res = res / n * (n - 1);
    }

    return res;
}

int main() {
    long long number;
    printf("请输入一个数字: ");
    if (scanf("%lld", &number) != 1) return 0;

    if (number <= 0) {
        printf("请输入正整数\n");
        return 0;
    }

    printf("phi(%lld) = %lld\n", number, euler_phi(number));

    return 0;
}
#include <stdio.h>

// 1. 使用迭代法求GCD（更稳健），最大公约数 (GCD)
long long GCD(long long a, long long b) {
    long long temp;
    while (b != 0) {
        temp = a % b;
        a = b;
        b = temp;
    }
    return a;
}

// 2. 防溢出求LCM，最小公倍数 (LCM)
long long LCM(long long a, long long b) {
    if (a == 0 || b == 0) return 0; // 防止除以0的边缘情况
    // 技巧：先除后乘
    return (a / GCD(a, b)) * b;
}

int main() {
    long long n, m;
    
    // 3. 使用标准格式符 %lld
    if (scanf("%lld %lld", &n, &m) != 2) return 1;

    // 4. 负数处理（你的代码里有，这很好，是加分项）
    if (n < 0 || m < 0) {
        printf("Input Error\n");
        return 0;
    }

    printf("%lld %lld\n", GCD(n, m), LCM(n, m));
    return 0;
}
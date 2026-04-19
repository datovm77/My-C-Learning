#include <iostream>
#include <vector>
#include <chrono>
using namespace std;

// 方法 1：朴素递归
long long fibNaive(int n) {
    if (n <= 1) return n;
    return fibNaive(n - 1) + fibNaive(n - 2);
}

// 方法 2：记忆化递归
vector<long long> memo;
long long fibMemo(int n) {
    if (n <= 1) return n;
    if (memo[n] != -1) return memo[n];
    memo[n] = fibMemo(n - 1) + fibMemo(n - 2);
    return memo[n];
}

// 方法 3：迭代
long long fibIter(int n) {
    if (n <= 1) return n;
    long long a = 0, b = 1, c;
    for (int i = 2; i <= n; i++) {
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main() {
    int n = 40;
    
    // 测试朴素递归
    auto start = chrono::high_resolution_clock::now();
    cout << "朴素: F(" << n << ") = " << fibNaive(n);
    auto end = chrono::high_resolution_clock::now();
    cout << "  耗时: " 
         << chrono::duration_cast<chrono::milliseconds>(end - start).count()
         << " ms" << endl;
    
    // 测试记忆化递归
    memo.assign(n + 1, -1);
    start = chrono::high_resolution_clock::now();
    cout << "记忆化: F(" << n << ") = " << fibMemo(n);
    end = chrono::high_resolution_clock::now();
    cout << "  耗时: "
         << chrono::duration_cast<chrono::microseconds>(end - start).count()
         << " μs" << endl;
    
    // 测试迭代
    start = chrono::high_resolution_clock::now();
    cout << "迭代: F(" << n << ") = " << fibIter(n);
    end = chrono::high_resolution_clock::now();
    cout << "  耗时: "
         << chrono::duration_cast<chrono::microseconds>(end - start).count()
         << " μs" << endl;
    
    return 0;
}
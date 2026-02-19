#include <iostream>

int main() {
    int count = 0;

    // 值捕获：Lambda 内部是 count 的副本，修改不影响外部
    auto byValue = [count]() mutable {
        count++;                          // mutable 才能修改副本
        std::cout << "内部: " << count << std::endl;
    };

    // 引用捕获：直接修改外部 count
    auto byRef = [&count]() {
        count++;
        std::cout << "内部: " << count << std::endl;
    };

    byValue(); // 内部: 1
    std::cout << "外部 count: " << count << std::endl; // 外部 count: 0 ← 未改变！

    byRef();   // 内部: 1
    std::cout << "外部 count: " << count << std::endl; // 外部 count: 1 ← 已改变！

    return 0;
}
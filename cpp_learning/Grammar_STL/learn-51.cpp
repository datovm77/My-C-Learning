#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = {1, 2, 3, 2, 5, 2, 7};

    std::cout << "remove前, size=" << v.size() << std::endl; // 7

    auto new_end = std::remove(v.begin(), v.end(), 2);

    std::cout << "remove后, size=" << v.size() << std::endl; // 仍然是 7！

    std::cout << "逻辑有效元素: ";
    for (auto it = v.begin(); it != new_end; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    // 输出: 1 3 5 7

    std::cout << "实际容器内容: ";
    for (int x : v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    // 输出可能是: 1 3 5 7 5 2 7 （尾部的值是未指定的）

    return 0;
}
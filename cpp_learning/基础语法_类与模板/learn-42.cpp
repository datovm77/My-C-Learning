// 练习函数模板特化，知识点：const char*的完全特化比较
#include <iostream>
#include <cstring>
using namespace std;

// 通用模板
template<typename T>
bool isEqual(T a, T b) {
    return a == b;
}

// 特化：针对 const char* 类型
template<>
bool isEqual<const char*>(const char* a, const char* b) {
    return strcmp(a, b) == 0;
}

int main() {
    cout << isEqual(10, 10) << endl;              // 1（使用通用模板）
    cout << isEqual("hello", "hello") << endl;    // 1
    
    const char* s1 = "hello";
    const char* s2 = "hello";
    cout << isEqual(s1, s2) << endl;              // 1（使用特化版本）
    
    return 0;
}

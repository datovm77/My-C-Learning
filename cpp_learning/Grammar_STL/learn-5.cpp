#include<iostream>
#include<string>
using namespace std;
void test07() {
    string s = "Hello, World! Hello, C++!";

    // ============ find：从左往右查找 ============

    // ① 查找子串首次出现的位置（返回下标，找不到返回 string::npos）
    size_t pos1 = s.find("Hello");
    cout << "find(\"Hello\") = " << pos1 << endl;  // 0

    // ② 从指定位置开始查找
    size_t pos2 = s.find("Hello", 1);  // 从下标 1 开始找
    cout << "find(\"Hello\", 1) = " << pos2 << endl;  // 14

    // ③ 查找单个字符
    size_t pos3 = s.find('W');
    cout << "find('W') = " << pos3 << endl;  // 7

    // ④ 查找不存在的内容
    size_t pos4 = s.find("Java");
    if (pos4 == string::npos) {
        cout << "\"Java\" 未找到！" << endl;  // 未找到
    }

    // ============ rfind：从右往左查找 ============

    // rfind 查找的是子串最后一次出现的位置
    size_t pos5 = s.rfind("Hello");
    cout << "rfind(\"Hello\") = " << pos5 << endl;  // 14
}

int main()
{

    test07();
}
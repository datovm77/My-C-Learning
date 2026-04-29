// 练习stack栈容器与括号匹配验证，知识点：stack压栈弹栈、括号匹配逻辑
#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isValid(const string& s) {
    stack<char> stk;

    for (char c : s) {
        // 遇到左括号，压入对应的右括号
        if (c == '(')  stk.push(')');
        else if (c == '[')  stk.push(']');
        else if (c == '{')  stk.push('}');
        else {
            // 遇到右括号
            // 如果栈为空，或者栈顶不匹配，返回 false
            if (stk.empty() || stk.top() != c) {
                return false;
            }
            stk.pop();  // 匹配成功，弹出
        }
    }

    // 最终栈为空说明全部匹配
    return stk.empty();
}

int main() {

    cout << isValid("()[]{}") << endl;   // 1 (true)
    cout << isValid("([{}])") << endl;   // 1 (true)
    cout << isValid("(]") << endl;       // 0 (false)
    cout << isValid("([)]") << endl;     // 0 (false)
    cout << isValid("{[]}") << endl;     // 1 (true)

    return 0;
}

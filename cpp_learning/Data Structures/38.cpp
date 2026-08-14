#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool IsMatching(char left, char right) {
    return (left == '(' && right == ')') ||
           (left == '[' && right == ']') ||
           (left == '{' && right == '}');
}

bool IsBalanced(const string &text) {
    stack<char> brackets;

    for (char ch : text) {
        if (ch == '(' || ch == '[' || ch == '{') {
            brackets.push(ch);
        } else if (ch == ')' || ch == ']' || ch == '}') {
            if (brackets.empty()) {
                return false;
            }

            char left = brackets.top();

            if (!IsMatching(left, ch)) {
                return false;
            }

            brackets.pop();
        }
    }

    return brackets.empty();
}

int main() {
    const string tests[] = {
        "{[()]}",
        "((a+b)*c)",
        "([)]",
        "(()",
        "())",
        ""
    };

    for (const string &text : tests) {
        cout << "\"" << text << "\" -> "
             << (IsBalanced(text) ? "balanced" : "not balanced")
             << endl;
    }

    return 0;
}

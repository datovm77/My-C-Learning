// 练习后缀表达式分词求值，词法分析与栈操作
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cctype>
//P1449 后缀表达式
struct Token
{
    bool isNumber;
    int value;
    char op;
};

// 方案1：先分词，再计算。
// 适合理解"词法分析(分词)" + "求值"两个阶段。
std::vector<Token> tokenizePostfix(const std::string &s)
{
    std::vector<Token> tokens;
    int current = 0;
    bool buildingNumber = false;

    for (char ch : s)
    {
        if (std::isdigit(static_cast<unsigned char>(ch)))
        {
            current = current * 10 + (ch - '0');
            buildingNumber = true;
        }
        else if (ch == '.')
        {
            if (buildingNumber)
            {
                tokens.push_back({true, current, 0});
                current = 0;
                buildingNumber = false;
            }
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            if (buildingNumber)
            {
                tokens.push_back({true, current, 0});
                current = 0;
                buildingNumber = false;
            }
            tokens.push_back({false, 0, ch});
        }
        else if (ch == '@')
        {
            if (buildingNumber)
            {
                tokens.push_back({true, current, 0});
            }
            break;
        }
    }

    return tokens;
}

bool evaluateTokens(const std::vector<Token> &tokens, int &result)
{
    std::stack<int> st;

    for (const Token &tk : tokens)
    {
        if (tk.isNumber)
        {
            st.push(tk.value);
            continue;
        }

        if (st.size() < 2)
        {
            return false;
        }

        int b = st.top();
        st.pop();
        int a = st.top();
        st.pop();

        switch (tk.op)
        {
        case '+':
            st.push(a + b);
            break;
        case '-':
            st.push(a - b);
            break;
        case '*':
            st.push(a * b);
            break;
        case '/':
            st.push(a / b);
            break; // C++ 整数除法本身就是向0取整
        default:
            return false;
        }
    }

    if (st.size() != 1)
    {
        return false;
    }

    result = st.top();
    return true;
}

int main()
{
    std::string s;
    std::getline(std::cin, s);

    std::vector<Token> tokens = tokenizePostfix(s);

    int ans = 0;
    if (!evaluateTokens(tokens, ans))
    {
        std::cout << "Invalid expression\n";
        return 0;
    }

    std::cout << ans << '\n';
    return 0;
}

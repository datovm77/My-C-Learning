// 练习后缀表达式递归求值，递归与分词处理
#include <iostream>
#include <string>
#include <vector>
#include <cctype>
//P1449 后缀表达式（递归法-难懂）
struct Token
{
    bool isNumber;
    int value;
    char op;
};

// 将后缀表达式分词成：数字token / 运算符token。
std::vector<Token> tokenize(const std::string &s)
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

// 方案2：递归求值（从后往前）。
// 对于后缀表达式：
// - 读到数字 => 返回该数字
// - 读到运算符op => 先递归得到右操作数，再递归得到左操作数
bool evalFromRight(const std::vector<Token> &tokens, int &idx, int &value)
{
    if (idx < 0)
    {
        return false;
    }

    const Token &tk = tokens[idx--];
    if (tk.isNumber)
    {
        value = tk.value;
        return true;
    }

    int right = 0;
    int left = 0;
    if (!evalFromRight(tokens, idx, right))
    {
        return false;
    }
    if (!evalFromRight(tokens, idx, left))
    {
        return false;
    }

    switch (tk.op)
    {
    case '+':
        value = left + right;
        break;
    case '-':
        value = left - right;
        break;
    case '*':
        value = left * right;
        break;
    case '/':
        value = left / right;
        break;
    default:
        return false;
    }

    return true;
}

int main()
{
    std::string s;
    std::getline(std::cin, s);

    std::vector<Token> tokens = tokenize(s);
    if (tokens.empty())
    {
        std::cout << "Invalid expression\n";
        return 0;
    }

    int idx = static_cast<int>(tokens.size()) - 1;
    int ans = 0;
    bool ok = evalFromRight(tokens, idx, ans);

    // idx == -1 代表所有token都被合法消费完。
    if (!ok || idx != -1)
    {
        std::cout << "Invalid expression\n";
        return 0;
    }

    std::cout << ans << '\n';
    return 0;
}

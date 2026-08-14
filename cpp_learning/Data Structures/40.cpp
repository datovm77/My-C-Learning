#include <cctype>
#include <iostream>
#include <stack>
#include <string>
// 重难点
bool IsOperator(char ch)
{
    return ch == '+' || ch == '-' ||
           ch == '*' || ch == '/';
}

bool IsOperand(char ch)
{
    return std::isalnum(static_cast<unsigned char>(ch));
}

int Precedence(char op)
{
    if (op == '+' || op == '-')
    {
        return 1;
    }

    if (op == '*' || op == '/')
    {
        return 2;
    }

    return 0;
}

bool InfixToPostfix(
    const std::string &infix,
    std::string &postfix)
{
    std::stack<char> operators;
    postfix.clear();

    for (char ch : infix)
    {
        if (std::isspace(static_cast<unsigned char>(ch)))
        {
            continue;
        }

        if (IsOperand(ch))
        {
            postfix += ch;
            continue;
        }

        if (ch == '(')
        {
            operators.push(ch);
            continue;
        }

        if (ch == ')')
        {
            while (!operators.empty() && operators.top() != '(')
            {
                postfix += operators.top();
                operators.pop();
            }

            if (operators.empty())
            {
                return false;
            }

            operators.pop();
            continue;
        }

        if (IsOperator(ch))
        {
            while (!operators.empty() &&
                   operators.top() != '(' &&
                   Precedence(operators.top()) >= Precedence(ch))
            {
                postfix += operators.top();
                operators.pop();
            }

            operators.push(ch);
            continue;
        }

        return false;
    }

    while (!operators.empty())
    {
        if (operators.top() == '(')
        {
            return false;
        }

        postfix += operators.top();
        operators.pop();
    }

    return true;
}

void PrintConversion(const std::string &infix)
{
    std::string postfix;

    std::cout << "Infix: " << infix << '\n';

    if (InfixToPostfix(infix, postfix))
    {
        std::cout << "Postfix: " << postfix << '\n';
    }
    else
    {
        std::cout << "Invalid expression\n";
    }

    std::cout << '\n';
}

int main()
{
    PrintConversion("A+B*C");
    PrintConversion("(A+B)*(C-D)");
    PrintConversion("A*(B+C)-D");
    PrintConversion("(A+B");
    PrintConversion("A+B)");

    return 0;
}

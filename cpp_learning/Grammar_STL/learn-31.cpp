// 练习用栈计算后缀表达式（逆波兰表达式）
#include <iostream>
#include <string>
#include <stack>
//P1449 后缀表达式
void test01(const std::string &s)
{
    std::stack<int> stk;

    int current = 0;
    bool buildingNumber = false;

    for (const char &ch : s)
    {
        if (ch <= '9' && ch >= '0')
        {
            current = current * 10 + (ch - '0');
            buildingNumber = true;
        }
        else if (ch == '.')
        {
            if (buildingNumber)
            {
                stk.push(current);
                current = 0;
                buildingNumber = false;
            }
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            if (buildingNumber)
            {
                stk.push(current);
                current = 0;
                buildingNumber = false;
            }

            if (stk.size() < 2)
            {
                std::cout << "Invalid expression\n";
                return;
            }

            int num2 = stk.top();
            stk.pop();
            int num1 = stk.top();
            stk.pop();

            switch (ch)
            {
            case '+':
                stk.push(num1 + num2);
                break;
            case '-':
                stk.push(num1 - num2);
                break;
            case '*':
                stk.push(num1 * num2);
                break;
            case '/':
                stk.push(num1 / num2);
                break;
            default:
                break;
            }
        }
        else if (ch == '@')
        {
            if (buildingNumber)
            {
                stk.push(current);
                current = 0;
                buildingNumber = false;
            }
            break;
        }
    }
    if (stk.empty())
    {
        std::cout << "Invalid expression\n";
        return;
    }
    std::cout << stk.top() << '\n';
}

int main()
{
    std::string str;
    std::getline(std::cin, str);
    test01(str);

    return 0;
}
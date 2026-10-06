#include <iostream>
#include <stack>

bool ifleft(char c)
{
    if (c == '(' || c == '[' || c == '{')
        return true;
    else
        return false;
}
bool ifright(char c)
{
    if (c == ')' || c == ']' || c == '}')
        return true;
    else
        return false;
}
bool ifmatch(char c, char c2)
{
    if (c == '(')
        return c2 == ')';
    else if (c == '[')
        return c2 == ']';
    else if (c == '{')
        return c2 == '}';
    return false;
}
bool CheckBalance(std::string line)
{
    std::stack<char> s1;

    for (int i = 0; i < static_cast<int>(line.length()); i++)
    {
        if (ifleft(line[i]))
        {
            s1.push(line[i]);
        }
        else if (ifright(line[i]))
        {
            if (s1.empty())
            {
                return false;
            }
            else
            {
                char c = s1.top();
                if (ifmatch(c, line[i]))
                    s1.pop();
                else
                    return false;
            }
        }
    }
    if (s1.empty())
        return true;
    else
        return false;
}
int main()
{

    int t;
    if (!(std::cin >> t))
        return 0;
    while (t--)
    {
        std::string line;
        std::cin >> line;
        if (CheckBalance(line))
            std::cout << "ok" << '\n';
        else
            std::cout << "error" << '\n';
    }
    return 0;
}
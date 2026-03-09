#include <iostream>
#include <string>
#include <stack>

bool isValid(const std::string &s)
{
    std::stack<char> stk;

    for (char c : s)
    {
        if(c=='(')  stk.push(')');
        else if(c=='[') stk.push(']');
        else if(c=='{') stk.push('}');
        else{
            //遇到左括号
            //如果栈为空，或者栈顶不匹配，返回false
            if(stk.empty() || stk.top()!=c)
            {
                return false;
            }
            stk.pop();
        }
    }
}

int main()
{ 
    std::string str = "2*(x+y)/(1-x)@";
    isValid(str);
    return 0;
}

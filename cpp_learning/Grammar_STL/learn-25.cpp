#include <iostream>
// P1739 表达式括号匹配
#include <stack>
#include <string>

void test01()
{
    std::stack<char> icon;
    std::string str;
    std::getline(std::cin, str);


    // 2*(x+y)/(1-x)@
    for(char ch:str)
    {
        if (ch == '@')
        {
            break;
        }

        if(ch=='('||ch==')')
        {
            if(ch=='(')
            {
                icon.push(ch);
            }
            else if(ch==')'&&!icon.empty()&&icon.top()=='(')
            {
                icon.pop();
            }
            else{
                icon.push(ch);
            }
        }        
    }


    if (icon.empty())
    {
        std::cout << "YES" << std::endl;
    }
    else
    {
        std::cout << "NO" << std::endl;
    }
}

int main()
{
    test01();
    return 0;
}
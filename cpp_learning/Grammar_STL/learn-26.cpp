#include <iostream>
// P1739 表达式括号匹配
#include <stack>
#include <string>

int main()
{
    std::string s;
    std::getline(std::cin,s);

    std::stack<char> st;

    for(char ch:s)
    {
        if(ch=='@') break;

        if(ch=='(') st.push(ch);
        else if(ch==')')
        {
            if(st.empty())
            {
                std::cout<<"NO\n";
                return 0;
            }
            st.pop();

        }

    }
    if(st.empty()) std::cout<<"YES\n";
    else std::cout<<"NO\n";

    return 0;

}

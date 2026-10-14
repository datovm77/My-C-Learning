#include <iostream>
#include <stack>
#include <string>
#include <sstream>

int main()
{
    std::ios::sync_with_stdio(0);
    std::string s1;
    std::cin >> s1;
    std::stack<int> st;
    int num = 0;

    for (char c : s1)
    {
        if (c >= '0' && c <= '9')
        {
            num = num * 10 + (c - '0');
        }
        else if (c == '.')
        {
            st.push(num);
            num = 0;
        }
        else if (c == '@')
        {
            break;
        }
        else
        {
            int b = st.top();
            st.pop();
            int a = st.top();
            st.pop();
            if (c == '+')
                st.push(a + b);
            else if (c == '-')
                st.push(a - b);
            else if (c == '*')
                st.push(a * b);
            else if (c == '/')
                st.push(a / b);
        }
    }
    std::cout << st.top() << '\n';
    return 0;
}
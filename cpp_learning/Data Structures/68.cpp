#include <iostream>
#include <string>
const int maxsize = 100;
class my_stack
{
public:
    char data[maxsize];
    int top;
};

void initstack(my_stack &s1)
{
    s1.top = -1;
}

// 旧: bool isempty(my_stack &s1)
bool isempty(const my_stack &s1)
{
    return s1.top == -1;
}

// 旧: bool isfull(my_stack &s1)
bool isfull(const my_stack &s1)
{
    return s1.top == maxsize - 1;
}

bool push(my_stack &s, char c)
{
    if (isfull(s))
        return false;
    s.data[++s.top] = c;
    return true;
}

bool pop(my_stack &s, char &c)
{
    if (isempty(s))
        return false;
    c = s.data[s.top--];
    return true;
}

// 旧: bool reverse_my(std::string &s1)
void reverse_my(std::string &s1)
{
    // 旧: if (s1.length() == 0) return true;
    if (s1.empty())
        return;
    my_stack s;
    initstack(s);
    // 旧: for (int i = 0; i < s1.length(); i++)
    for (int i = 0; i < static_cast<int>(s1.length()); i++)
    {
        push(s, s1[i]);
    }
    // 旧: std::string s2 = "";
    std::string s2;
    s2.reserve(s1.length());
    // 旧: for (int i = 0; i < s1.length(); i++) { char c; pop(s, c); s2 += c; }
    char c;
    while (pop(s, c))
    {
        s2 += c;
    }
    s1 = s2;
}

int main()
{
    std::string str;
    int t;
    if (!(std::cin >> t))
        return 0;
    while (t--)
    {
        std::cin >> str;
        my_stack s1;
        initstack(s1);
        // 旧: 循环体内单独声明 char c;
        char c;
        // 旧: for (int i = 0; i < str.length(); i++)
        for (int i = 0; i < static_cast<int>(str.length()); i++)
        {
            if (str[i] == '#')
                pop(s1, c);
            // 旧: push(s1, str[i]);
            else if (!push(s1, str[i]))
                break;
        }
        // 旧: std::string rev = "";
        std::string rev;
        while (pop(s1, c))
        {
            rev += c;
        }
        reverse_my(rev);
        // 旧: if (rev.length() == 0)
        if (rev.empty())
            std::cout << "NULL" << '\n';
        else
            std::cout << rev << '\n';
    }
    return 0;
}

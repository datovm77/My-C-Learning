#include <iostream>
#include <cstring>
using namespace std;

const int MAX_SIZE = 100;

struct CharStack
{
    char data[MAX_SIZE];
    int top;
};

void InitStack(CharStack &S) { S.top = -1; }
bool IsEmpty(const CharStack &S) { return S.top == -1; }
bool IsFull(const CharStack &S) { return S.top == MAX_SIZE - 1; }

bool Push(CharStack &S, char c)
{
    if (IsFull(S))
        return false;
    S.data[++S.top] = c;
    return true;
}

bool Pop(CharStack &S, char &c)
{
    if (IsEmpty(S))
        return false;
    c = S.data[S.top--];
    return true;
}

// 用栈反转字符串
bool ReverseString(char str[])
{
    CharStack S;
    InitStack(S);

    int len = strlen(str);

    // 第一步：所有字符入栈
    for (int i = 0; i < len; i++)
    {
        if (!Push(S, str[i]))
        {
            return false; // 字符串超过固定栈容量
        }
    }

    // 第二步：依次出栈，覆盖原字符串
    for (int i = 0; i < len; i++)
    {
        if (!Pop(S, str[i]))
            return false;
    }
    return true;
}

int main()
{
    char str[] = "Hello World";
    cout << "反转前：" << str << endl;
    if (ReverseString(str))
    {
        cout << "反转后：" << str << endl;
    }
    else
    {
        cout << "反转失败：字符串长度不能超过 " << MAX_SIZE << endl;
    }
    return 0;
}
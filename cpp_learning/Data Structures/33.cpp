#include <iostream>
using namespace std;

const int MAX_SIZE = 100; // 栈的最大容量

// ==================== 顺序栈结构定义 ====================
struct ArrayStack
{
    int data[MAX_SIZE]; // 存储栈元素的数组
    int top;            // 栈顶指针
};

// ==================== 初始化 ====================
void InitStack(ArrayStack &S)
{
    S.top = -1; // top = -1 表示空栈
}

// ==================== 判空 ====================
bool IsEmpty(ArrayStack S)
{
    return S.top == -1;
}

// ==================== 判满 ====================
bool IsFull(ArrayStack S)
{
    return S.top == MAX_SIZE - 1;
}

// ==================== 入栈 ====================
bool Push(ArrayStack &S, int x)
{
    if (IsFull(S))
    {
        cout << "栈满，无法入栈！" << endl;
        return false; // 栈满，也叫"上溢"（Overflow）
    }
    S.top++;           // ① 栈顶指针先加 1
    S.data[S.top] = x; // ② 再把元素放到栈顶位置
    // 上面两行可以合并为：S.data[++S.top] = x;
    return true;
}

// ==================== 出栈 ====================
bool Pop(ArrayStack &S, int &x)
{
    if (IsEmpty(S))
    {
        cout << "栈空，无法出栈！" << endl;
        return false; // 栈空，也叫"下溢"（Underflow）
    }
    x = S.data[S.top]; // ① 先取出栈顶元素
    S.top--;           // ② 栈顶指针再减 1
    // 上面两行可以合并为：x = S.data[S.top--];
    return true;
}

// ==================== 读取栈顶（不弹出） ====================
bool GetTop(ArrayStack S, int &x)
{
    if (IsEmpty(S))
    {
        cout << "栈空！" << endl;
        return false;
    }
    x = S.data[S.top]; // 只读不修改 top
    return true;
}

// ==================== 测试 ====================
int main()
{
    ArrayStack S;
    InitStack(S);

    // 入栈测试
    Push(S, 10);
    Push(S, 20);
    Push(S, 30);
    cout << "依次入栈：10, 20, 30" << endl;

    // 读取栈顶
    int topVal;
    GetTop(S, topVal);
    cout << "当前栈顶元素：" << topVal << endl; // 输出 30

    // 出栈测试
    int popVal;
    Pop(S, popVal);
    cout << "出栈元素：" << popVal << endl; // 输出 30
    Pop(S, popVal);
    cout << "出栈元素：" << popVal << endl; // 输出 20
    Pop(S, popVal);
    cout << "出栈元素：" << popVal << endl; // 输出 10

    // 此时栈空
    cout << "栈是否为空：" << (IsEmpty(S) ? "是" : "否") << endl;

    return 0;
}
// 用顺序栈实现字符串逆序
#include <algorithm>
#include <iostream>
#include <string>

namespace {

// 原: const int maxsize = 100;
// 常量名改为全小写加 k 前缀/全大写风格，避免与 std 作用域下的 maxsize 概念混淆
constexpr int kMaxSize = 100;

// 原: class my_stack（类名下划线风格不统一），且成员 data / top 全部 public
class MyStack
{
public:
    // 原: 需要额外调用 initstack(s) 手动把 top 置为 -1；改由构造函数完成
    MyStack() : top_(-1) {}

    // 原: bool isempty(my_stack &s1)  —— 改为 const 成员函数，不再需要传出参
    bool isEmpty() const
    {
        return top_ == -1;
    }

    // 原: bool isfull(my_stack &s1)
    bool isFull() const
    {
        return top_ == kMaxSize - 1;
    }

    // 原: bool push(my_stack &s, char c)
    bool push(char c)
    {
        if (isFull())
            return false;
        data_[++top_] = c;
        return true;
    }

    // 原: bool pop(my_stack &s, char &c)
    bool pop(char &c)
    {
        if (isEmpty())
            return false;
        c = data_[top_--];
        return true;
    }

private:
    char data_[kMaxSize]; // 原: public char data[maxsize]
    int top_;             // 原: public int top
};

// 原: bool reverse(std::string &s1)
// 1) reverse 与 std::reverse 同名，属于标准库保留风格的命名；
// 2) 返回值恒为 true，没有意义，改成 void
void reverseString(std::string &s)
{
    // 原: if (s1.length() == 0) return true;  —— 串长为 0 时下面两个循环自然不执行，无需特判
    // 原: 完全没有检查容量，串长超过 100 时 push 静默失败，pop 读到未初始化的字符
    if (s.size() > static_cast<std::size_t>(kMaxSize))
    {
        std::reverse(s.begin(), s.end()); // 超出固定栈容量时的兜底，避免未定义行为
        return;
    }

    MyStack st;
    // 原: for (int i = 0; i < s1.length(); i++)  —— int 与 size_t 比较有符号/无符号隐患
    for (std::size_t i = 0; i < s.size(); ++i)
    {
        st.push(s[i]); // 容量已校验，必定成功
    }

    // 原: std::string s2 = ""; 逐个 += 拼接，缺少容量预分配
    std::string reversed;
    reversed.reserve(s.size());

    // 原: char c; 未初始化，且 pop 的返回值被忽略（栈空时 c 为未定义值）
    for (char c = '\0'; st.pop(c);)
    {
        reversed += c;
    }

    s = reversed; // 原: s1 = s2;
}

} // namespace

int main()
{
    // 原: 缺少这两句，cin/cout 未解绑，频繁刷屏时效率很差
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    std::string str;
    int t;
    // 原: std::cin >> t; 未判断输入是否有效
    if (!(std::cin >> t))
        return 0;

    while (t--)
    {
        std::cin >> str;
        reverseString(str);
        std::cout << str << '\n';
    }
    return 0;
}

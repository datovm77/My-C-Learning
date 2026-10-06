/*
 * 69.cpp —— 行编辑（教学版，手写栈实现）
 *
 * 题目：
 *   第一行输入整数 t，表示有 t 行字符串；
 *   之后每行一个字符串，'#' 表示退格（把最近输入的一个字符删掉），
 *   如果栈里已经没有字符可退，就什么都不做、不报错；
 *   每行处理完输出结果，结果为空输出 NULL。
 *
 * 为什么用栈：
 *   退格删的永远是"最后输入的那个字符"，这正是后进先出（LIFO）的特性，
 *   所以用栈来模拟光标前的编辑内容最合适。
 *
 * 整体思路（三步）：
 *   1. 从左到右扫描字符串：
 *        普通字符 -> 入栈
 *        '#'      -> 出栈（栈空则忽略）
 *   2. 处理完后，栈里从栈顶到栈底是"逆序"的结果，需要倒回来；
 *   3. 借助一个辅助栈再倒一次，两次反转 = 原顺序，即可正序输出。
 *
 * 数据结构：顺序栈（数组 + 栈顶下标），完全手写，不使用 STL 的 stack。
 */

#include <iostream>
#include <string>

// ------------------------- 手写顺序栈 -------------------------
class SqStack
{
public:
    // 构造时把栈顶下标置为空栈标记
    SqStack() : top_(kEmpty) {}

    bool empty() const { return top_ == kEmpty; }

    bool full() const { return top_ == kMaxSize - 1; }

    // 入栈：先移动栈顶，再放元素
    bool push(char c)
    {
        if (full())
            return false; // 栈满，调用方负责决定怎么处理
        data_[++top_] = c;
        return true;
    }

    // 出栈：先取元素，再移动栈顶；栈空返回 false
    bool pop(char &out)
    {
        if (empty())
            return false;
        out = data_[top_--];
        return true;
    }

private:
    static const int kMaxSize = 100; // 栈的最大容量，按题目数据范围调整
    static const int kEmpty = -1;    // 空栈时栈顶下标
    char data_[kMaxSize];
    int top_; // 栈顶元素的下标，空栈为 -1
};

// ------------------------- 主流程 -------------------------
int main()
{
    int t;
    if (!(std::cin >> t))
        return 0;

    while (t--)
    {
        std::string line;
        std::cin >> line;

        SqStack edit; // 主栈：保存当前"行上"已确认的字符
        for (std::size_t i = 0; i < line.length(); i++)
        {
            char ch = line[i];
            if (ch == '#')
            {
                char trash;
                edit.pop(trash); // 栈空时返回 false，不报错、不操作
            }
            else if (!edit.push(ch))
            {
                break; // 栈满，后面的字符放不下，直接丢弃
            }
        }

        // 正序输出：主栈弹出是逆序，压进辅助栈再弹出就恢复正序
        SqStack aux;
        char c;
        while (edit.pop(c))
            aux.push(c);

        if (aux.empty())
        {
            std::cout << "NULL" << '\n';
        }
        else
        {
            while (aux.pop(c))
                std::cout << c;
            std::cout << '\n';
        }
    }

    return 0;
}

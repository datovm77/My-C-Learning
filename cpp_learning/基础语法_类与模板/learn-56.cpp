#include <iostream>
#include <string>

class Cmoney
{
    int yuan;
    int jiao;
    int fen;

public:
    Cmoney(int yuan = 0, int jiao = 0, int fen = 0) : yuan(yuan), jiao(jiao), fen(fen) {}

    friend Cmoney operator+(const Cmoney &a, const Cmoney &b);
    friend Cmoney operator-(const Cmoney &a, const Cmoney &b);

    void show()
    {
        std::cout << yuan << "元" << jiao << "角" << fen << "分" << '\n';
    }
};

Cmoney operator+(const Cmoney &a, const Cmoney &b)
{
    // 错误写法：直接改 a，会把左操作数顺手修改掉，不符合 + 的常规语义
    // a.fen += b.fen;
    // if (a.fen >= 10) { ... }
    Cmoney c = a;

    c.fen += b.fen;
    if (c.fen >= 10)
    {
        c.jiao += c.fen / 10;
        c.fen %= 10;
    }

    c.jiao += b.jiao;
    if (c.jiao >= 10)
    {
        c.yuan += c.jiao / 10;
        c.jiao %= 10;
    }

    c.yuan += b.yuan;
    return c;
}

Cmoney operator-(const Cmoney &a, const Cmoney &b)
{
    // 错误写法：`int yuan_num = -a.jiao / 10 + 1;`
    // 这个写法在刚好是 -10、-20 这类整十负数时会多借 1。
    // 正确做法是按“需要借几次 10”来处理，或者直接用总分数计算。
    Cmoney c = a;

    c.fen -= b.fen;
    if (c.fen < 0)
    {
        int borrow = (-c.fen + 9) / 10;
        c.jiao -= borrow;
        c.fen += borrow * 10;
    }

    c.jiao -= b.jiao;
    if (c.jiao < 0)
    {
        int borrow = (-c.jiao + 9) / 10;
        c.yuan -= borrow;
        c.jiao += borrow * 10;
    }

    c.yuan -= b.yuan;
    return c;
}

int main()
{
    int t;
    std::cin >> t;

    while (t--)
    {
        int fen;
        int yuan;
        int jiao;
        std::cin >> yuan >> jiao >> fen;
        Cmoney c1(yuan, jiao, fen);
        std::string fun;

        while (std::cin >> fun && fun != "stop")
        {
            int fen_in;
            int yuan_in;
            int jiao_in;
            std::cin >> yuan_in >> jiao_in >> fen_in;
            Cmoney c2(yuan_in, jiao_in, fen_in);
            if (fun == "add")
            {
                c1 = c1 + c2;
            }
            else if (fun == "minus")
            {
                c1 = c1 - c2;
            }
        }
        c1.show();
    }
}

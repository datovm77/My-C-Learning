#include <iostream>
#include <string>
#include <algorithm>

template <class T>
class Cryption
{
private:
    T ptxt[100]; // 明文
    T ctxt[100]; // 密文
    T key;
    int len; // 长度
public:
    Cryption(T tk, T tt[], int n) // 参数依次对应密钥、明文、长度
    {
        key = tk;
        std::copy(tt, tt + n, ptxt);
        len = n;
    }
    void encrypt()
    {
        T max = *std::max_element(ptxt, ptxt + len);
        std::transform(ptxt, ptxt + len, ctxt, [max, k = key](T x)
                       { return max - x + k; });
    }
    void print() // 打印，无需改造
    {
        int i;
        for (i = 0; i < len - 1; i++)
        {
            std::cout << ctxt[i] << " ";
        }
        std::cout << ctxt[i] << std::endl;
    }
};

int main()
{
    int i;
    int length; // 长度
    int ik, itxt[100];
    double dk, dtxt[100];
    char ck, ctxt[100];
    // 整数加密
    std::cin >> ik >> length;
    for (i = 0; i < length; i++)
    {
        std::cin >> itxt[i];
    }
    Cryption<int> ic(ik, itxt, length);
    ic.encrypt();
    ic.print();
    // 浮点数加密
    std::cin >> dk >> length;
    for (i = 0; i < length; i++)
    {
        std::cin >> dtxt[i];
    }
    Cryption<double> dc(dk, dtxt, length);
    dc.encrypt();
    dc.print();
    // 字符加密
    std::cin >> ck >> length;
    for (i = 0; i < length; i++)
    {
        std::cin >> ctxt[i];
    }
    Cryption<char> cc(ck, ctxt, length);
    cc.encrypt();
    cc.print();

    return 0;
}
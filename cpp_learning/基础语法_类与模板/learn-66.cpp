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
    // 旧写法是在此处直接写函数体；本题要求构造函数必须在类外实现。
    Cryption(T tk, T tt[], int n); // 参数依次对应密钥、明文、长度
    // 旧写法是在此处直接写函数体；本题要求加密方法必须在类外实现。
    void encrypt();
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

// 类模板的成员函数在类外定义时，必须再次写 template <class T> 和 Cryption<T>::。
template <class T>
Cryption<T>::Cryption(T tk, T tt[], int n)
{
    key = tk;
    std::copy(tt, tt + n, ptxt);
    len = n;
}

template <class T>
void Cryption<T>::encrypt()
{
    T maxValue = *std::max_element(ptxt, ptxt + len);
    const T encryptionKey = key;
    // 旧写法 [maxValue, k = key] 是 C++14 初始化捕获，严格 C++11 下会编译失败。
    std::transform(ptxt, ptxt + len, ctxt, [maxValue, encryptionKey](T x)
                   { return maxValue - x + encryptionKey; });
}

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

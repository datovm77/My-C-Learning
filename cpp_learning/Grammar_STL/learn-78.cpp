// 练习复数类Complex，友元函数实现加减运算与输出
#include <iostream>
using namespace std;

class Complex
{
private:
    double real; // 实部
    double imag; // 虚部

public:
    Complex() : real(0), imag(0) {}
    Complex(double r, double i) : real(r), imag(i) {}

    // 友元函数，复数 c1 + c2
    friend Complex addCom(const Complex& c1, const Complex& c2);
    // 友元函数，复数 c1 - c2
    friend Complex minusCom(const Complex& c1, const Complex& c2);
    // 友元函数，输出复数
    friend void outCom(const Complex& c);
};

Complex addCom(const Complex& c1, const Complex& c2)
{
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

Complex minusCom(const Complex& c1, const Complex& c2)
{
    return Complex(c1.real - c2.real, c1.imag - c2.imag);
}

void outCom(const Complex& c)
{
    cout << "(" << c.real << "," << c.imag << ")" << endl;
}

int main()
{
    double r, i;
    cin >> r >> i;
    Complex result(r, i);

    int n;
    cin >> n;

    for (int k = 0; k < n; ++k)
    {
        char op;
        double nr, ni;
        cin >> op >> nr >> ni;
        Complex next(nr, ni);

        if (op == '+')
        {
            result = addCom(result, next);
        }
        else if (op == '-')
        {
            result = minusCom(result, next);
        }

        outCom(result);
    }

    return 0;
}

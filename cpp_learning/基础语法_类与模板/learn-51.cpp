// 练习运算符重载，知识点：Complex类的加减乘运算
#include <iostream>
using namespace std;

class Complex
{
private:
    float real, image;

public:
    Complex(float x = 0, float y = 0);
    friend Complex operator+(Complex&, Complex&);
    friend Complex operator-(Complex&, Complex&);
    friend Complex operator*(Complex&, Complex&);
    void show();
};

Complex::Complex(float x, float y)
{
    real = x;
    image = y;
}

Complex operator+(Complex& c1, Complex& c2)
{
    return Complex(c1.real + c2.real, c1.image + c2.image);
}

Complex operator-(Complex& c1, Complex& c2)
{
    return Complex(c1.real - c2.real, c1.image - c2.image);
}

Complex operator*(Complex& c1, Complex& c2)
{
    return Complex(c1.real * c2.real - c1.image * c2.image,
                   c1.image * c2.real + c1.real * c2.image);
}

void Complex::show()
{
    cout << "Real=" << real << " Image=" << image << endl;
}

int main()
{
    float real1, image1, real2, image2;
    cin >> real1 >> image1;
    cin >> real2 >> image2;

    Complex c1(real1, image1), c2(real2, image2);

    Complex sum = c1 + c2;
    Complex difference = c1 - c2;
    Complex product = c1 * c2;

    sum.show();
    difference.show();
    product.show();

    return 0;
}

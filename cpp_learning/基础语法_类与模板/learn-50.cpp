// 练习运算符重载，知识点：Fraction类的加减乘除运算
#include <iostream>
using namespace std;

class Fraction
{
private:
    int fz, fm;
    int commonDivisor();
    void contracted();

public:
    Fraction(int = 0, int = 1);
    Fraction(Fraction&);
    Fraction operator+(Fraction);
    Fraction operator-(Fraction);
    Fraction operator*(Fraction);
    Fraction operator/(Fraction);
    void set(int = 0, int = 1);
    void display();
};

int Fraction::commonDivisor()
{
    return 1;
}

void Fraction::contracted()
{
}

Fraction::Fraction(int a, int b)
{
    set(a, b);
}

Fraction::Fraction(Fraction& f)
{
    fz = f.fz;
    fm = f.fm;
}

Fraction Fraction::operator+(Fraction f)
{
    Fraction result(fz * f.fm + f.fz * fm, fm * f.fm);
    return result;
}

Fraction Fraction::operator-(Fraction f)
{
    Fraction result(fz * f.fm - f.fz * fm, fm * f.fm);
    return result;
}

Fraction Fraction::operator*(Fraction f)
{
    Fraction result(fz * f.fz, fm * f.fm);
    return result;
}

Fraction Fraction::operator/(Fraction f)
{
    Fraction result(fz * f.fm, fm * f.fz);
    return result;
}

void Fraction::set(int a, int b)
{
    fz = a;
    fm = b;
}

void Fraction::display()
{
    cout << "fraction=" << fz << "/" << fm << endl;
}

int main()
{
    int fz1, fm1, fz2, fm2;
    cin >> fz1 >> fm1 >> fz2 >> fm2;

    Fraction f1(fz1, fm1), f2(fz2, fm2);

    (f1 + f2).display();
    (f1 - f2).display();
    (f1 * f2).display();
    (f1 / f2).display();

    return 0;
}

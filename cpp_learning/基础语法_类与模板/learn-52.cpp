// 练习运算符重载，知识点：Vector类的加减运算
#include <iostream>
using namespace std;

class Vector
{
private:
    int vec[5];

public:
    Vector(int v[]);
    Vector();
    Vector(const Vector& obj);
    Vector operator+(const Vector& obj);
    Vector operator-(const Vector& obj);
    void print();
};

Vector::Vector(int v[])
{
    for (int i = 0; i < 5; i++)
    {
        vec[i] = v[i];
    }
}

Vector::Vector()
{
    for (int i = 0; i < 5; i++)
    {
        vec[i] = 0;
    }
}

Vector::Vector(const Vector& obj)
{
    for (int i = 0; i < 5; i++)
    {
        vec[i] = obj.vec[i];
    }
}

Vector Vector::operator+(const Vector& obj)
{
    Vector result;

    for (int i = 0; i < 5; i++)
    {
        result.vec[i] = vec[i] + obj.vec[i];
    }

    return result;
}

Vector Vector::operator-(const Vector& obj)
{
    Vector result;

    for (int i = 0; i < 5; i++)
    {
        result.vec[i] = vec[i] - obj.vec[i];
    }

    return result;
}

void Vector::print()
{
    for (int i = 0; i < 5; i++)
    {
        cout << vec[i] << " ";
    }
    cout << endl;
}

int main()
{
    int a[5], b[5];

    for (int i = 0; i < 5; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < 5; i++)
    {
        cin >> b[i];
    }

    Vector v1(a), v2(b);

    (v1 + v2).print();
    (v1 - v2).print();

    return 0;
}

// 练习运算符重载，知识点：MyMatrix类的矩阵乘法
#include <iostream>
using namespace std;

class MyMatrix
{
private:
    int n;
    int** data;

public:
    MyMatrix(int order = 0);
    MyMatrix(const MyMatrix& obj);
    ~MyMatrix();
    MyMatrix& operator=(const MyMatrix& obj);
    MyMatrix operator*(const MyMatrix& obj);
    void input();
    void print();
};

MyMatrix::MyMatrix(int order)
{
    n = order;
    data = new int*[n];

    for (int i = 0; i < n; i++)
    {
        data[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            data[i][j] = 0;
        }
    }
}

MyMatrix::MyMatrix(const MyMatrix& obj)
{
    n = obj.n;
    data = new int*[n];

    for (int i = 0; i < n; i++)
    {
        data[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            data[i][j] = obj.data[i][j];
        }
    }
}

MyMatrix::~MyMatrix()
{
    for (int i = 0; i < n; i++)
    {
        delete[] data[i];
    }
    delete[] data;
}

MyMatrix& MyMatrix::operator=(const MyMatrix& obj)
{
    if (this == &obj)
    {
        return *this;
    }

    for (int i = 0; i < n; i++)
    {
        delete[] data[i];
    }
    delete[] data;

    n = obj.n;
    data = new int*[n];

    for (int i = 0; i < n; i++)
    {
        data[i] = new int[n];
        for (int j = 0; j < n; j++)
        {
            data[i][j] = obj.data[i][j];
        }
    }

    return *this;
}

MyMatrix MyMatrix::operator*(const MyMatrix& obj)
{
    MyMatrix result(n);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < n; k++)
            {
                result.data[i][j] += data[i][k] * obj.data[k][j];
            }
        }
    }

    return result;
}

void MyMatrix::input()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> data[i][j];
        }
    }
}

void MyMatrix::print()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j > 0)
            {
                cout << " ";
            }
            cout << data[i][j];
        }
        cout << endl;
    }
}

int main()
{
    int c, n;
    cin >> c >> n;

    MyMatrix result(n);
    result.input();

    for (int i = 1; i < c; i++)
    {
        MyMatrix matrix(n);
        matrix.input();
        result = result * matrix;
    }

    result.print();

    return 0;
}

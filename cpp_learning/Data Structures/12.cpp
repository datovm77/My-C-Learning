// 练习自定义vector类，知识点：深拷贝、拷贝构造、赋值运算符重载、友元函数
#include <iostream>

class vector_self
{
private:
    int *data;
    int n;

public:
    vector_self(int *data, int size) : data(new int[size]), n(size)
    {
        for (int i = 0; i < n; ++i)
        {
            this->data[i] = data[i];
        }
    }

    vector_self(int size) : data(new int[size]{}), n(size) {}

    vector_self()
    {
        data = new int[5]{0, 1, 2, 3, 4};
        n = 5;
    }

    vector_self(const vector_self &other) : data(new int[other.n]), n(other.n)
    {
        for (int i = 0; i < n; ++i)
        {
            data[i] = other.data[i];
        }
    }

    vector_self &operator=(const vector_self &other)
    {
        if (this != &other)
        {
            delete[] data;

            n = other.n;
            data = new int[n];

            for (int i = 0; i < n; ++i)
            {
                data[i] = other.data[i];
            }
        }

        return *this;
    }

    ~vector_self()
    {
        delete[] data;
    }

    friend vector_self add(const vector_self v1, const vector_self v2)
    {
        vector_self result(v1.n);

        for (int i = 0; i < v1.n; ++i)
        {
            result.data[i] = v1.data[i] + v2.data[i];
        }

        return result;
    }

    void print() const
    {
        for (int i = 0; i < n; ++i)
        {
            if (i != 0)
                std::cout << " ";

            std::cout << data[i];
        }
        std::cout << '\n';
    }
};

int main()
{
    int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i)
    {
        int size;
        std::cin >> size;

        int *p = new int[size]{};
        for (int j = 0; j < size; ++j)
        {
            std::cin >> p[j];
        }

        int *p1 = new int[size]{};
        for (int j = 0; j < size; ++j)
        {
            std::cin >> p1[j];
        }

        vector_self v(p, size);
        vector_self v1(p1, size);

        delete[] p;
        delete[] p1;

        v.print();
        v1.print();

        add(v, v1).print();
    }

    return 0;
}
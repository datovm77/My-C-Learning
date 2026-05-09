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
            this->data[i] = data[i];
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
            data[i] = other.data[i];
    }

    vector_self &operator=(const vector_self &other)
    {
        if (this != &other)
        {
            delete[] data;
            n = other.n;
            data = new int[n];

            for (int i = 0; i < n; ++i)
                data[i] = other.data[i];
        }
        return *this;
    }

    ~vector_self()
    {
        delete[] data;
    }

    friend vector_self add(const vector_self &v1, const vector_self &v2)
    {
        int size = v1.n;
        vector_self v(size);

        for (int i = 0; i < size; ++i)
        {
            v.data[i] = v1.data[i] + v2.data[i];
        }

        return v;
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
            int temp;
            std::cin >> temp;
            p[j] = temp;
        }
        int *p1 = new int[size]{};
        for (int j = 0; j < size; ++j)
        {
            int temp;
            std::cin >> temp;
            p1[j] = temp;
        }
        vector_self v(p, size);
        vector_self v1(p1, size);

        // ========== BUG 4: p 和 p1 在构造后未释放，造成内存泄漏 ==========
        // 旧代码: 没有 delete[] p, p1
        delete[] p;
        delete[] p1;

        v.print();
        v1.print();

        vector_self v3 = add(v, v1);
        v3.print();
        int size2;
        std::cin >> size2;
        int *pp = new int[size2]{};
        for (int j = 0; j < size2; ++j)
        {
            int temp2;
            std::cin >> temp2;
            pp[j] = temp2;
        }
        int *pp1 = new int[size2]{};
        for (int j = 0; j < size2; ++j)
        {
            int temp2;
            std::cin >> temp2;
            pp1[j] = temp2;
        }
        vector_self vv(pp, size2);
        vector_self vv1(pp1, size2);

        // ========== BUG 5: pp 和 pp1 在构造后未释放，造成内存泄漏 ==========
        delete[] pp;
        delete[] pp1;

        vv.print();
        vv1.print();
        vector_self vv3 = add(vv, vv1);
        vv3.print();
    }

    return 0;
}
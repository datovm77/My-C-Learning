#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
class CVector
{
    int *data, n;

public:
    CVector(int n = 0, int a[] = nullptr) : n(n)
    {
        data = n ? new int[n] : nullptr;
        for (int i = 0; i < n; i++)
            data[i] = a[i];
    }
    CVector(const CVector &o) : n(o.n)
    {
        data = n ? new int[n] : nullptr;
        for (int i = 0; i < n; i++)
            data[i] = o.data[i];
    }
    CVector &operator=(const CVector &o)
    {
        if (this != &o)
        {
            int *p = o.n ? new int[o.n] : nullptr;
            for (int i = 0; i < o.n; i++)
                p[i] = o.data[i];
            delete[] data;
            data = p;
            n = o.n;
        }
        return *this;
    }
    ~CVector()
    {
        delete[] data;
    }
    double Average() const
    {
        double s = 0;
        for (int i = 0; i < n; i++)
            s += data[i];
        return s / n;
    }
    void print() const
    {
        for (int i = 0; i < n; i++)
            cout << ' ' << data[i];
    }
};
class CStudent
{
    string name;
    CVector score;

public:
    CStudent(string n, int m, int a[]) : name(n), score(m, a) {}
    void print() const
    {
        cout << name;
        score.print();
        cout << ' ' << fixed << setprecision(2) << score.Average() << endl;
    }
};
int main()
{
    string name;
    int n;
    while (cin >> name >> n)
    {
        int *a = new int[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];
        CStudent(name, n, a).print();
        delete[] a;
    }
    return 0;
}
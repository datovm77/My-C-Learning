#include <iostream>
#include <string>

using namespace std;

class CXGraph
{
private:
    int size;

    void Enlarge()
    {
        if (size < 21)
        {
            size += 2;
        }
    }

    void Shrink()
    {
        if (size > 1)
        {
            size -= 2;
        }
    }

public:
    explicit CXGraph(int n) : size(n) {}

    CXGraph &operator++()
    {
        Enlarge();
        return *this;
    }

    CXGraph operator++(int)
    {
        CXGraph temp(*this);
        Enlarge();
        return temp;
    }

    CXGraph &operator--()
    {
        Shrink();
        return *this;
    }

    CXGraph operator--(int)
    {
        CXGraph temp(*this);
        Shrink();
        return temp;
    }

    friend ostream &operator<<(ostream &os, const CXGraph &graph)
    {
        for (int i = 0; i < graph.size; ++i)
        {
            int padding = i < graph.size - 1 - i ? i : graph.size - 1 - i;
            int width = graph.size - 2 * padding;

            for (int j = 0; j < padding; ++j)
            {
                os << ' ';
            }
            for (int j = 0; j < width; ++j)
            {
                os << 'X';
            }
            os << '\n';
        }
        return os;
    }
};

int main()
{
    int t, n;
    string command;
    cin >> n;
    CXGraph xGraph(n);
    cin >> t;
    while (t--)
    {
        cin >> command;
        if (command == "show++")
        {
            cout << xGraph++ << endl;
        }
        else if (command == "++show")
        {
            cout << ++xGraph << endl;
        }
        else if (command == "show--")
        {
            cout << xGraph-- << endl;
        }
        else if (command == "--show")
        {
            cout << --xGraph << endl;
        }
        else if (command == "show")
        {
            cout << xGraph << endl;
        }
    }
    return 0;
}

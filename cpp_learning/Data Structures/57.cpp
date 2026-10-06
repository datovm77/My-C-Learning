#include <iostream>
using namespace std;

class SeqList
{
private:
    int data[1000];
    int length;
    int maxLength;

public:
    SeqList()
    {
        length = 0;
        maxLength = 1000;
    }

    void insert(int x)
    {
        data[length++] = x;
    }

    void merge(int a[], int n, int b[], int m)
    {
        int i = 0, j = 0;

        while (i < n && j < m)
        {
            if (a[i] < b[j])
                insert(a[i++]);
            else
                insert(b[j++]);
        }

        while (i < n)
            insert(a[i++]);

        while (j < m)
            insert(b[j++]);
    }

    void print()
    {
        cout << length << " ";
        for (int i = 0; i < length; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int n, m;
    int a[200], b[200];

    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    cin >> m;
    for (int i = 0; i < m; i++)
        cin >> b[i];

    SeqList list;
    list.merge(a, n, b, m);
    list.print();

    return 0;
}
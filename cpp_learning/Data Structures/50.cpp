#include <iostream>
using namespace std;
int main()
{
    int t, i, n;
    char c;
    cin >> t;
    while (t--)
    {
        cin >> c >> n;
        if (c == 'I')
        {
            int *p = new int[n];
            int sum = 0;
            for (i = 0; i < n; i++)
            {
                cin >> *(p + i);
                sum += *(p + i);
            }
            cout << sum / n << endl;
            delete[] p;
        }
        else if (c == 'C')
        {
            char *p = new char[n];
            int max = 0;
            for (i = 0; i < n; i++)
            {
                cin >> *(p + i);
                if (*(p + i) > *(p + max))
                    max = i;
            }
            cout << *(p + max) << endl;
            delete[] p;
        }
        else
        {
            float *p = new float[n];
            int min = 0;
            for (i = 0; i < n; i++)
            {
                cin >> *(p + i);
                if (*(p + i) < *(p + min))
                    min = i;
            }
            cout << *(p + min) << endl;
            delete[] p;
        }
    }
    return 0;
}

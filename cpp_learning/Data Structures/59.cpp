#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int a[50];

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }

        // 去重
        int len = 0;

        for (int i = 0; i < n; i++)
        {
            // 第一个元素，或者当前元素和前一个不同
            if (i == 0 || a[i] != a[i - 1])
            {
                a[len] = a[i];
                len++;
            }
        }

        // 输出
        cout << len;
        for (int i = 0; i < len; i++)
        {
            cout << " " << a[i];
        }
        cout << endl;
    }

    return 0;
}
// 练习用unique_ptr管理动态数组与指针偏移访问
#include <iostream>
#include <memory>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        unique_ptr<int[]> scores = make_unique<int[]>(n);

        for (int i = 0; i < n; ++i)
        {
            cin >> scores[i];
        }

        int queryIndex1Based;
        cin >> queryIndex1Based;

        int *base = scores.get();
        int midIndex = n / 2;
        int *pMid = base + midIndex;

        cout << *(pMid - 1) << ' ' << *(pMid + 1) << '\n';

        int queryIndex = queryIndex1Based - 1;

        int dist = queryIndex - midIndex;
        int *pQuery = pMid + dist;
        cout << *pQuery << '\n';
    }

    return 0;
}
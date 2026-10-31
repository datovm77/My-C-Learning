#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &a)
{
    int n = a.size();

    if (n == 0)
    {
        return 0;
    }

    int slow = 1;

    for (int fast = 1; fast < n; fast++)
    {
        if (a[fast] != a[slow - 1])
        {
            a[slow] = a[fast];
            slow++;
        }
    }

    return slow;
}

int main()
{
    vector<int> a = {1, 1, 2, 2, 3, 3, 4};

    int len = removeDuplicates(a);

    cout << "去重后的元素：";

    for (int i = 0; i < len; i++)
    {
        cout << a[i] << " ";
    }

    cout << "\n有效长度：" << len << '\n';

    return 0;
}
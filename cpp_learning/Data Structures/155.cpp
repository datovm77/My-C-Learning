#include <iostream>
#include <vector>
using namespace std;

// 将 a[l...r] 排序
void mergeSort(vector<int> &a,
               vector<int> &tmp,
               int l, int r)
{
    // 只有一个元素，已经有序
    if (l >= r)
        return;

    int mid = l + (r - l) / 2;

    // 1. 排序左半部分
    mergeSort(a, tmp, l, mid);

    // 2. 排序右半部分
    mergeSort(a, tmp, mid + 1, r);

    // 3. 合并两个有序部分
    int i = l;
    int j = mid + 1;
    int k = l;

    while (i <= mid && j <= r)
    {
        if (a[i] <= a[j])
            tmp[k++] = a[i++];
        else
            tmp[k++] = a[j++];
    }

    // 左半部分可能有剩余
    while (i <= mid)
        tmp[k++] = a[i++];

    // 右半部分可能有剩余
    while (j <= r)
        tmp[k++] = a[j++];

    // 把合并结果复制回原数组
    for (int p = l; p <= r; p++)
        a[p] = tmp[p];
}

int main()
{
    int n;
    cin >> n;

    vector<int> a(n);
    vector<int> tmp(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    if (n > 0)
        mergeSort(a, tmp, 0, n - 1);

    for (int x : a)
        cout << x << " ";
}
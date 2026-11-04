// P1223 排队接水
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;

struct Person
{
    int id;   // 原始编号
    int time; // 接水时间
};

int main()
{
    int n;
    cin >> n;

    vector<Person> a(n);

    for (int i = 0; i < n; i++)
    {
        cin >> a[i].time;
        a[i].id = i + 1;
    }

    // 贪心：接水时间短的人先接水
    sort(a.begin(), a.end(), [](const Person &x, const Person &y)
         {
        if (x.time != y.time)
            return x.time < y.time;
        return x.id < y.id; });

    // 计算所有人的总等待时间
    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += 1LL * a[i].time * (n - i - 1);
    }

    // 输出接水顺序
    for (int i = 0; i < n; i++)
    {
        if (i > 0)
            cout << " ";
        cout << a[i].id;
    }
    cout << '\n';

    // 输出平均等待时间
    cout << fixed << setprecision(2)
         << (double)sum / n << '\n';

    return 0;
}

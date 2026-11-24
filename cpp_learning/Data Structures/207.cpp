// CSP201809B 买菜
#include <iostream>
#include <unordered_map>
using namespace std;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(nullptr);
    int n;
    cin >> n;
    unordered_map<int, int> chat;

    n *= 2;
    while (n--)
    {
        int a, b;
        cin >> a >> b;
        for (int i = a; i < b; i++)
        {
            chat[i]++;
        }
    }
    int sum = 0;
    for (auto &[x, y] : chat)
    {
        if (y == 2)
        {
            sum++;
        }
    }

    cout << sum << '\n';
}
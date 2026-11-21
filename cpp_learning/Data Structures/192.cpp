// CSP202403A 词频统计
#include <iostream>
#include <string>
#include <map>
#include <utility>
#include <vector>
using namespace std;
int n, m;
map<pair<int, int>, int> w;

// 有x篇文章包含单词i y次
vector<pair<int, int>> sum;
int main()
{
    cin >> n >> m;
    sum.resize(m + 1, {0, 0});
    for (int i = 1; i <= n; i++)
    {
        int number;
        cin >> number;
        for (int j = 0; j < number; j++)
        {
            int word;
            cin >> word;

            // 第i篇文章包含数字m的次数
            w[{i, word}]++;
        }
    }

    for (auto [a, z] : w)
    {
        auto [x, y] = a;

        sum[y].first++;
        sum[y].second += z;
    }

    for (int i = 1; i <= m; i++)
    {
        cout << sum[i].first << ' ' << sum[i].second << '\n';
    }
}
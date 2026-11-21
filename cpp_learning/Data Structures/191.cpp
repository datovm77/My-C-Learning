// CSP202403B 相似度计算
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;
int n, m;

// 有多少个不同的单词同时出现在两篇文章中 A ∩ B
unordered_map<string, int> words_same;

// 一共包含了多少个不同的单词。 A U B
unordered_map<string, int> words_all;
void tolower_string(string &s1)
{
    transform(s1.begin(), s1.end(), s1.begin(), [](unsigned char c)
              { return tolower(c); });
}

int main()
{
    cin >> n >> m;

    while (n--)
    {
        string s;
        cin >> s;
        tolower_string(s);
        if (!words_all[s])
        {
            words_all[s] = 1;
        }
        if (!words_same[s])
        {
            words_same[s] = 1;
        }
    }

    while (m--)
    {
        string s;
        cin >> s;
        tolower_string(s);
        if (!words_all[s])
        {
            words_all[s] = 1;
        }
        if (words_same[s])
        {
            words_same[s] = 2;
        }
    }

    int words_same_s = 0;
    for (auto [key, value] : words_same)
    {
        if (value == 2)
            words_same_s++;
    }
    cout << words_same_s << '\n';
    cout << words_all.size() << '\n';
}
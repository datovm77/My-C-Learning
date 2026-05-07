// 练习按行读入成绩并访问中间相邻元素，知识点：getline、istringstream、vector下标访问
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <limits>
using namespace std;

int main()
{
    int t;
    cin >> t;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 吃掉换行

    for (int cs = 0; cs < t; ++cs)
    {
        string line;
        getline(cin, line); // 一整行成绩

        while (line.empty())
            getline(cin, line); // 防止空行

        vector<int> scores;
        istringstream iss(line);
        int x;
        while (iss >> x)
            scores.push_back(x);

        int idx;
        cin >> idx;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        int n = (int)scores.size();
        int mid = n / 2; // 题目通常保证 n 为奇数且>=3

        cout << scores[mid - 1] << ' ' << scores[mid + 1] << '\n';
        cout << scores[idx - 1] << '\n';
    }
    return 0;
}

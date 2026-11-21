// CSP202512A 集合
#include <iostream>
#include <vector>
using namespace std;
int n, m;
vector<int> value;
int main()
{
    cin >> n >> m;
    value.resize(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> value[i];
    }

    vector<vector<int>> S;
    vector<vector<int>> T;
    S.resize(m + 1);
    T.resize(m + 1);
    for (int i = 1; i <= m; i++)
    {
        int number;
        cin >> number;
        S[i].push_back(0);
        for (int j = 1; j <= number; j++)
        {
            int n;
            cin >> n;
            S[i].push_back(n);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        int number;
        cin >> number;
        T[i].push_back(0);
        for (int j = 1; j <= number; j++)
        {
            int n;
            cin >> n;
            T[i].push_back(n);
        }
    }
    for (int i = 1; i <= m; i++)
    {
        bool real_result = (S[i] == T[i]);
        int size_s = (int)S[i].size() - 1;
        int size_t = (int)T[i].size() - 1;
        int cal_s = value[S[i][1]];
        int cal_t = value[T[i][1]];

        for (int j = 2; j <= size_s; j++)
        {
            cal_s ^= value[S[i][j]];
        }
        for (int j = 2; j <= size_t; j++)
        {
            cal_t ^= value[T[i][j]];
        }
        bool C_result = (cal_s == cal_t);

        if (real_result == C_result)
            cout << "correct" << '\n';
        else
            cout << "wrong" << '\n';
    }
    return 0;
}
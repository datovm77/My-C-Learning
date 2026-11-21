// CSP202512B 数字变换
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int n, m;

int f_x_k(int x, int k)
{
    return ((x * x + k * k) % 8) ^ k;
}

string int_to_string(int x)
{
    string s = "";
    while (x != 0)
    {
        int n = x % 2;
        x /= 2;
        s = (char)(n + '0') + s;
    }
    return s;
}

int string_to_int(string s)
{
    int size = (int)s.size();
    int result = 0;
    int index = 0;
    while (size--)
    {
        if (s[index] == '1')
        {
            result += (1 << size);
        }
        index++;
    }
    return result;
}

int g_out(int f, int k)
{
    string s = int_to_string(f);
    int size = (int)s.size();
    int res = 9 - size;
    string res_s = "";
    while (res--)
    {
        res_s += '0';
    }
    s = res_s + s;
    string aa = s.substr(0, 3);
    string bb = s.substr(3, 3);
    string cc = s.substr(6, 3);
    int a = string_to_int(aa);
    int b = string_to_int(bb);
    int c = string_to_int(cc);

    int a_g = b;
    int b_g = c ^ f_x_k(b, k);
    int c_g = a ^ f_x_k(c, k);
    aa = int_to_string(a_g);
    while ((int)aa.size() < 3)
    {
        aa = '0' + aa;
    }
    bb = int_to_string(b_g);
    while ((int)bb.size() < 3)
    {
        bb = '0' + bb;
    }
    cc = int_to_string(c_g);
    while ((int)cc.size() < 3)
    {
        cc = '0' + cc;
    }
    s = aa + bb + cc;
    return string_to_int(s);
}

int main()
{
    cin >> n >> m;
    vector<long long> result_F;
    result_F.resize(n);
    vector<long long> ki;
    ki.resize(m);
    vector<int> input(512, -1);
    for (int i = 0; i < m; i++)
    {
        cin >> ki[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> result_F[i];
        input[result_F[i]] = 0;
    }
    for (int i = 0; i < 512; i++)
    {
        int input_num = i;
        for (int j = 0; j < m; j++)
        {
            input_num = g_out(input_num, ki[j]);
        }
        input[input_num] = i;
    }
    for (int i = 0; i < n; i++)
    {
        if (input[result_F[i]] != -1)
        {
            if (i != 0)
                cout << ' ';
            cout << input[result_F[i]];
        }
    }
    cout << '\n';
    return 0;
}
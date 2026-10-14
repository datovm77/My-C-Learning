#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
std::string matched_Prefix_Postfix(std::string &str)
{
    int len = static_cast<int>(str.size());
    if (len <= 1)
        return "";
    std::unordered_map<std::string, int> m1;

    std::string qian_str = "";
    std::string hou_str = "";
    for (int i = 0; i < len - 1; i++)
    {
        qian_str += str[i];
        m1[qian_str]++;
    }

    for (int i = len - 1; i > 0; i--)
    {
        hou_str = str[i] + hou_str;
        m1[hou_str]++;
    }
    std::string max_qian = "";
    int max_len = 1;

    for (const auto &[key, value] : m1)
    {
        if (value > max_len)
        {
            max_len = value;
            max_qian = key;
        }
        else if (value == max_len && (value != 1))
        {
            if (max_qian.size() < key.size())
            {
                max_qian = key;
            }
        }
    }
    return max_qian;
}

int main()
{

    int n;
    std::cin >> n;
    while (n--)
    {
        std::string s;
        std::cin >> s;
        std::string result = matched_Prefix_Postfix(s);
        int len = static_cast<int>(result.size());
        if (len == 0)
            std::cout << "empty" << '\n';
        else
            std::cout << result << '\n';
    }
}

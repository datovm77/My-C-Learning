#include <iostream>
#include <string>

std::string matched_Prefix_Postfix(std::string str)
{
    for (int len = static_cast<int>(str.size()) - 1; len > 0; len--)
    {
        std::string prefix = str.substr(0, len);
        std::string postfix = str.substr(str.size() - len);

        if (prefix == postfix)
            return prefix;
    }

    return "";
}

int main()
{
    int n;
    std::cin >> n;

    while (n--)
    {
        std::string str;
        std::cin >> str;

        std::string result = matched_Prefix_Postfix(str);
        if (result.empty())
            std::cout << "empty" << '\n';
        else
            std::cout << result << '\n';
    }

    return 0;
}

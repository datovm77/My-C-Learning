#include <iostream>
#include <string>

//加密密钥
void test01()
{
    int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i)
    {
        std::string s1;
        std::string num_s;

        std::cin >> s1;
        std::cin >> num_s;

        int index = 0;
        size_t num_size = num_s.size();

        for (const char &ch : s1)
        {
            char temp_ch = ch;
            char num = num_s[index];
            int count = (int)(num - '0');
            if (index == ((int)num_size) - 1)
            {
                index = 0; // 控制密钥的循环
            }
            else
            {
                index++;
            }

            if (temp_ch >= 'a' && temp_ch <= 'z')
            {
                temp_ch = (temp_ch - 'a' + count) % 26 + 'a';
            }
            else
            {
                temp_ch = (temp_ch - 'A' + count) % 26 + 'A';
            }
            std::cout << temp_ch;
        }
        std::cout << '\n';
    }
}

int main()
{
    test01();

    return 0;
}
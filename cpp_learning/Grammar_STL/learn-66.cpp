// 练习电话号码类，拷贝构造函数中进行合法性校验
#include <iostream>
#include <string>

class phone_num
{
private:
    std::string phone = "";

public:
    phone_num(const std::string &phone_out) : phone(phone_out) {}

    phone_num(const phone_num &p1)
    {
        for (const char &c1 : p1.phone)
        {
            if (c1 <= '9' && c1 >= '0')
            {
                continue;
            }
            else
            {
                std::cout << "Illegal phone number" << '\n';
                return;
            }
        }

        if ((p1.phone[0] == '2' || p1.phone[0] == '3' || p1.phone[0] == '4') && p1.phone.size() == 7)
        {
            phone = "8";
            phone += p1.phone;
            std::cout << phone << '\n';
        }
        else if ((p1.phone[0] == '5' || p1.phone[0] == '6' || p1.phone[0] == '7' || p1.phone[0] == '8') && p1.phone.size() == 7)
        {
            phone = "2";
            phone += p1.phone;
            std::cout << phone << '\n';
        }
        else
        {
            phone = "";
            std::cout << "Illegal phone number" << '\n';
        }
    }
};

int main()
{
    int t;
    std::cin >> t;
    for (int i = 0; i < t; ++i)
    {
        std::string s1;
        std::cin >> s1;
        phone_num p1(s1);
        phone_num p2(p1);
    }
    return 0;
}

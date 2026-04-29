// 练习账户类继承与多态，虚函数计算利息与格式化输出
#include <iostream>
#include <deque>
#include <algorithm>
#include <string>

class phone
{
private:
    std::string name;
    bool status;
    std::string phone_num;
    char type;

public:
    phone(const std::string &in_name, bool in_status, const std::string &in_phone_num, char in_type)
        : name(in_name), status(in_status), phone_num(in_phone_num), type(in_type) {}

    ~phone()
    {
        std::cout << phone_num << " destructed." << '\n';
    }

    bool operator==(const phone &other) const
    {
        return phone_num == other.phone_num;
    }

    std::string get_name() const
    {
        return name;
    }

    std::string get_phone_num() const
    {
        return phone_num;
    }

    std::string get_status() const
    {
        if (status)
        {
            return "use";
        }
        else
        {
            return "unuse";
        }
    }

    char get_type() const
    {
        return type;
    }
};

int main()
{
    std::deque<phone> dq;
    for (int i = 0; i < 3; ++i)
    {
        std::string phone_name;
        char type;
        bool status;
        std::string name;
        std::cin >> phone_name >> type >> status >> name;
        std::cout << phone_name << " constructed." << '\n';
        dq.emplace_front(name, status, phone_name, type);
    }

    int t;
    std::cin >> t;
    while (t--)
    {
        std::string check_name;
        std::cin >> check_name;
        int flag = 0;
        for (const phone &p1 : dq)
        {
            if (p1.get_phone_num() == check_name)
            {
                std::cout << "Phone=" << p1.get_phone_num() << "--Type=" << p1.get_type()
                          << "--State=" << p1.get_status() << "--Owner=" << p1.get_name() << '\n';
                flag = 1;
                break;
            }
        }
        if (!flag)
        {
            std::cout << "wrong number." << '\n';
        }
    }

    return 0;
}

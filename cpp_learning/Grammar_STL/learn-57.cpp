#include <iostream>
#include <string>
#include <vector>

class Account
{
public:
    std::string account;
    std::string name;
    double balance;

public:
    Account()
    {
    }
    Account(std::string m_account, std::string m_name, double m_balance) : account(m_account), name(m_name), balance(m_balance) {}

    void save(double num)
    {
        this->balance = this->balance + num;
        std::cout << "saving ok!" << '\n';
    }
    void withdraw(double num)
    {
        if (num <= balance)
        {
            this->balance = this->balance - num;
            std::cout << "withdraw ok!" << '\n';
        }
        else
        {
            std::cout << "sorry! over limit!" << '\n';
        }
    }
    void check()
    {
        std::cout << name << "'s balance is " << balance << '\n';
    }
};

void test01()
{
    for (int i = 0; i < 2; ++i)
    {
        Account a1;
        std::cin >> a1.account >> a1.name >> a1.balance;
        a1.check();
        double in;
        std::cin >> in;
        a1.save(in);
        a1.check();
        double out;
        std::cin >> out;
        a1.withdraw(out);
        a1.check();
    }
}

int main()
{
    test01();

    return 0;
}
#include <iostream>
#include <string>

class CPeople
{
protected:
    std::string id{};
    std::string name{};
};

class CInternetUser : public CPeople
{
protected:
    std::string password{};

public:
    void registerUser(const std::string& userName, const std::string& userId, const std::string& userPassword)
    {
        name = userName;
        id = userId;
        password = userPassword;
    }

    bool login(const std::string& userId, const std::string& userPassword) const
    {
        return id == userId && password == userPassword;
    }
};

class CBankCustomer : public CPeople
{
protected:
    double balance{0.0};

public:
    void openAccount(const std::string& userName, const std::string& userId)
    {
        name = userName;
        id = userId;
    }

    bool deposit(double money)
    {
        balance += money;
        return true;
    }

    bool withdraw(double money)
    {
        if (balance < money)
        {
            return false;
        }

        balance -= money;
        return true;
    }
};

class CInternetBankCustomer : public CInternetUser, public CBankCustomer
{
private:
    double internetBalance{0.0};
    double previousBalance{0.0};
    double profit{0.0};
    double todayInterest{0.0};
    double previousInterest{0.0};

public:
    bool deposit(double money)
    {
        if (!CBankCustomer::withdraw(money))
        {
            return false;
        }

        internetBalance += money;
        return true;
    }

    bool withdraw(double money)
    {
        if (internetBalance < money)
        {
            return false;
        }

        internetBalance -= money;
        CBankCustomer::deposit(money);
        return true;
    }

    void setInterest(double interest)
    {
        todayInterest = interest;
    }

    void calculateProfit()
    {
        profit = previousBalance * previousInterest / 10000.0;
        internetBalance += profit;
        previousBalance = internetBalance;
        previousInterest = todayInterest;
    }

    bool login(const std::string& userId, const std::string& userPassword) const
    {
        if (!CInternetUser::login(userId, userPassword))
        {
            return false;
        }

        if (CInternetUser::id != CBankCustomer::id)
        {
            return false;
        }

        if (CInternetUser::name != CBankCustomer::name)
        {
            return false;
        }

        return true;
    }

    void print() const
    {
        std::cout << "Name: " << CInternetUser::name << " ID: " << CInternetUser::id << '\n';
        std::cout << "Bank balance: " << CBankCustomer::balance << '\n';
        std::cout << "Internet bank balance: " << internetBalance << '\n';
        std::cout << '\n';
    }
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 0;
    int no_of_days = 0;
    std::string i_xm;
    std::string i_id;
    std::string i_mm;
    std::string b_xm;
    std::string b_id;
    std::string ib_id;
    std::string ib_mm;
    double money = 0.0;
    double interest = 0.0;
    char op_code = '\0';

    std::cin >> t;
    while (t--)
    {
        std::cin >> i_xm >> i_id >> i_mm;
        std::cin >> b_xm >> b_id;
        std::cin >> ib_id >> ib_mm;

        CInternetBankCustomer ib_user;

        ib_user.registerUser(i_xm, i_id, i_mm);
        ib_user.openAccount(b_xm, b_id);

        if (!ib_user.login(ib_id, ib_mm))
        {
            std::cout << "Password or ID incorrect" << '\n';
            continue;
        }

        std::cin >> no_of_days;
        for (int i = 0; i < no_of_days; ++i)
        {
            std::cin >> op_code >> money >> interest;
            switch (op_code)
            {
            case 'S':
            case 's':
                if (!ib_user.deposit(money))
                {
                    std::cout << "Bank balance not enough" << '\n';
                    continue;
                }
                break;
            case 'T':
            case 't':
                if (!ib_user.withdraw(money))
                {
                    std::cout << "Internet bank balance not enough" << '\n';
                    continue;
                }
                break;
            case 'D':
            case 'd':
                ib_user.CBankCustomer::deposit(money);
                break;
            case 'W':
            case 'w':
                if (!ib_user.CBankCustomer::withdraw(money))
                {
                    std::cout << "Bank balance not enough" << '\n';
                    continue;
                }
                break;
            default:
                std::cout << "Illegal input" << '\n';
                continue;
            }

            ib_user.setInterest(interest);
            ib_user.calculateProfit();
            ib_user.print();
        }
    }

    return 0;
}

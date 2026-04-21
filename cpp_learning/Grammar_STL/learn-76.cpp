#include <iostream>
#include <string>
using namespace std;

class Account
{
private:
    static double count;
    static double interestRate;
    string accno, accname;
    double balance;

public:
    Account(string ac, string na, double ba);
    ~Account();
    void deposit(double amount);
    void withdraw(double amount);
    double getBalance();
    void show();
    static double getCount();
    static void setInterestRate(double rate);
    static double getInterestRate();
    friend void update(Account &a);
};

double Account::count = 0;
double Account::interestRate = 0;

Account::Account(string ac, string na, double ba) : accno(ac), accname(na), balance(ba)
{
    count += ba;
}

Account::~Account()
{
    count -= balance;
}

void Account::deposit(double amount)
{
    balance += amount;
    count += amount;
}

void Account::withdraw(double amount)
{
    balance -= amount;
    count -= amount;
}

double Account::getBalance()
{
    return balance;
}

void Account::show()
{
    cout << accno << " " << accname << " " << balance << endl;
}

double Account::getCount()
{
    return count;
}

void Account::setInterestRate(double rate)
{
    interestRate = rate;
}

double Account::getInterestRate()
{
    return interestRate;
}

void update(Account &a)
{
    double interest = a.balance * Account::getInterestRate();
    a.balance += interest;
    Account::count += interest;
}

int main()
{
    double rate;
    int n;
    cin >> rate;
    Account::setInterestRate(rate);

    cin >> n;

    Account **accounts = new Account *[n];

    for (int i = 0; i < n; i++)
    {
        string accno, accname;
        double initBalance, depositAmt, withdrawAmt;
        cin >> accno >> accname >> initBalance >> depositAmt >> withdrawAmt;

        accounts[i] = new Account(accno, accname, initBalance);

        accounts[i]->deposit(depositAmt);
        double balanceAfterDeposit = accounts[i]->getBalance();

        update(*accounts[i]);
        double balanceAfterInterest = accounts[i]->getBalance();

        accounts[i]->withdraw(withdrawAmt);
        double balanceAfterWithdraw = accounts[i]->getBalance();

        cout << accno << " " << accname << " "
             << balanceAfterDeposit << " "
             << balanceAfterInterest << " "
             << balanceAfterWithdraw << endl;
    }

    cout << Account::getCount() << endl;

    for (int i = 0; i < n; i++)
    {
        delete accounts[i];
    }
    delete[] accounts;

    return 0;
}

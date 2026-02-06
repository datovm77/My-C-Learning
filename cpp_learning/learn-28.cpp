#include <iostream>
#include <string>
using namespace std;
class BankAccount
{
private:
    const int accountNumber; // 常量账号
    string ownerName;       // 引用持有人姓名
    double balance;
    static int totalAccounts;

public:
    // 完整的初始化列表示例
    BankAccount(int accNum, const string &owner, double initial = 0.0)
        : accountNumber(accNum), // 常量必须初始化
          ownerName(owner),      // 引用必须初始化
          balance(initial)       // 普通成员
    {
        totalAccounts++;
        cout << "Account " << accountNumber << " created" << endl;
    }

    void deposit(double amount)
    {
        balance += amount;
    }

    void display()
    {
        cout << "Account: " << accountNumber
             << ", Owner: " << ownerName
             << ", Balance: $" << balance << endl;
    }

    static int getTotalAccounts()
    {
        return totalAccounts;
    }
};

int BankAccount::totalAccounts = 0;

// 使用示例
int main()
{
    string name1 = "Alice";
    string name2 = "Bob";

    BankAccount acc1(1001, name1, 1000.0);
    BankAccount acc2(1002, name2, 500.0);

    acc1.display();
    // name2 = "gem";
    acc2.display();

    cout << "Total accounts: " << BankAccount::getTotalAccounts() << endl;
    return 0;
}
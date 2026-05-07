// 练习账户类继承与多态，知识点：虚函数、派生类、拷贝构造、格式化输出
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class Account {
private:
    int number;      // 8-digit account number
    char type;       // 'P' for person, 'E' for enterprise
    double balance;
    double rate;

public:
    Account(int num = 0, char t = 'P', double bal = 0.0, double r = 0.0)
        : number(num), type(t), balance(bal), rate(r) {}

    virtual ~Account() {}

    // Calculate interest and add to balance
    virtual void calculateInterest() {
        double interest = balance * rate;
        balance += interest;
        cout << "Account=" << number << "--sum=";
        // Output as integer if it's a whole number
        if (balance == (long long)balance) {
            cout << (long long)balance;
        } else {
            cout << balance;
        }
        cout << endl;
    }

    // Query: output all account information
    virtual void query() const {
        cout << "Account=" << number << "--";
        if (type == 'P') {
            cout << "Person";
        } else {
            cout << "Enterprise";
        }
        cout << "--sum=";
        // Avoid scientific notation
        if (balance == (long long)balance) {
            cout << (long long)balance;
        } else {
            cout << balance;
        }
        cout << "--rate=";
        cout << fixed << setprecision(3) << rate;
        cout.unsetf(ios::fixed);
        cout << endl;
    }

    // Getters
    int getNumber() const { return number; }
    char getType() const { return type; }
    double getBalance() const { return balance; }
    double getRate() const { return rate; }

    // Setters
    void setNumber(int num) { number = num; }
    void setType(char t) { type = t; }
    void setBalance(double bal) { balance = bal; }
    void setRate(double r) { rate = r; }
};

class CurrentAccount : public Account {
public:
    CurrentAccount(int num = 0, char t = 'P', double bal = 0.0)
        : Account(num, t, bal, 0.005) {}
};

class FixedAccount : public Account {
public:
    // Copy constructor from CurrentAccount
    FixedAccount(const CurrentAccount& current)
        : Account(current.getNumber() + 50000000, current.getType(),
                  current.getBalance(), 0.015) {}

    FixedAccount(int num = 0, char t = 'P', double bal = 0.0)
        : Account(num, t, bal, 0.015) {}
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int num;
        char type;
        double balance;
        cin >> num >> type >> balance;

        CurrentAccount current(num, type, balance);
        FixedAccount fixed(current);

        char op1, op2;
        cin >> op1 >> op2;

        // First operation on current account
        if (op1 == 'C') {
            current.calculateInterest();
        } else if (op1 == 'P') {
            current.query();
        }

        // Second operation on fixed account
        if (op2 == 'C') {
            fixed.calculateInterest();
        } else if (op2 == 'P') {
            fixed.query();
        }
    }

    return 0;
}

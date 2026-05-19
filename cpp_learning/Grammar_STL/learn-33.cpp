#include <iostream>
#include <cstring>
using namespace std;

class CPeople {
protected:
    char id[20];
    char name[10];
};

class CInternetUser : public CPeople {
protected:
    char password[20];
public:
    void registerUser(const char* n, const char* i, const char* pwd) {
        strcpy(name, n);
        strcpy(id, i);
        strcpy(password, pwd);
    }
};

class CBankCustomer : public CPeople {
protected:
    double balance;
public:
    CBankCustomer() : balance(0) {}
    void openAccount(const char* n, const char* i) {
        strcpy(name, n);
        strcpy(id, i);
    }
    bool deposit(double money) {
        balance += money;
        return true;
    }
    bool withdraw(double money) {
        if (balance < money) return false;
        balance -= money;
        return true;
    }
};

class CInternetBankCustomer : public CInternetUser, public CBankCustomer {
    double balance;
    double prevBalance;
    double todayProfit;
    double todayYield;
    double yesterdayYield;
public:
    CInternetBankCustomer()
        : balance(0), prevBalance(0), todayProfit(0), todayYield(0), yesterdayYield(0) {}
    bool deposit(double money) {
        if (CBankCustomer::balance < money) return false;
        CBankCustomer::balance -= money;
        balance += money;
        return true;
    }
    bool withdraw(double money) {
        if (balance < money) return false;
        balance -= money;
        CBankCustomer::balance += money;
        return true;
    }
    void setInterest(double interest) {
        todayYield = interest;
    }
    void calculateProfit() {
        todayProfit = prevBalance * yesterdayYield / 10000.0;
        balance += todayProfit;
        prevBalance = balance;
        yesterdayYield = todayYield;
    }
    bool login(const char* i, const char* pwd) {
        if (strcmp(CInternetUser::id, i) != 0 || strcmp(CInternetUser::password, pwd) != 0)
            return false;
        if (strcmp(CInternetUser::name, CBankCustomer::name) != 0 ||
            strcmp(CInternetUser::id, CBankCustomer::id) != 0)
            return false;
        return true;
    }
    void print() {
        cout << "Name: " << CInternetUser::name << " ID: " << CInternetUser::id << endl;
        cout << "Bank balance: " << CBankCustomer::balance << endl;
        cout << "Internet bank balance: " << balance << endl;
        cout << endl;
    }
};

int main() {
    int t, no_of_days, i;
    char i_xm[20], i_id[20], i_mm[20], b_xm[20], b_id[20], ib_id[20], ib_mm[20];
    double money, interest;
    char op_code;

    cin >> t;
    while (t--) {
        cin >> i_xm >> i_id >> i_mm;
        cin >> b_xm >> b_id;
        cin >> ib_id >> ib_mm;

        CInternetBankCustomer ib_user;
        ib_user.registerUser(i_xm, i_id, i_mm);
        ib_user.openAccount(b_xm, b_id);

        if (ib_user.login(ib_id, ib_mm) == 0) {
            cout << "Password or ID incorrect" << endl;
            continue;
        }

        cin >> no_of_days;
        for (i = 0; i < no_of_days; i++) {
            cin >> op_code >> money >> interest;
            switch (op_code) {
            case 'S': case 's':
                if (ib_user.deposit(money) == 0) {
                    cout << "Bank balance not enough" << endl;
                    continue;
                }
                break;
            case 'T': case 't':
                if (ib_user.withdraw(money) == 0) {
                    cout << "Internet bank balance not enough" << endl;
                    continue;
                }
                break;
            case 'D': case 'd':
                ib_user.CBankCustomer::deposit(money);
                break;
            case 'W': case 'w':
                if (ib_user.CBankCustomer::withdraw(money) == 0) {
                    cout << "Bank balance not enough" << endl;
                    continue;
                }
                break;
            default:
                cout << "Illegal input" << endl;
                continue;
            }
            ib_user.setInterest(interest);
            ib_user.calculateProfit();
            ib_user.print();
        }
    }
    return 0;
}

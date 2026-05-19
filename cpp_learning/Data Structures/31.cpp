#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class CMembership
{
protected:
    int card_no;
    int points;

public:
    CMembership(int no) : card_no(no), points(0) {}
};

class CCreditCard
{
protected:
    int card_no;
    string name;
    int limit;
    float bill;
    int points;

public:
    CCreditCard(int no, string n, int lim)
        : card_no(no), name(n), limit(lim), bill(0), points(0) {}
};

class CTravelCreditCard : public CMembership, public CCreditCard
{
public:
    CTravelCreditCard(int mem_no, int cred_no, string n, int lim)
        : CMembership(mem_no), CCreditCard(cred_no, n, lim) {}

    void order(float m)
    {
        if (m > limit) return;
        bill += m;
        limit -= (int)m;
        CCreditCard::points += (int)m;
        CMembership::points += (int)m;
    }

    void consume(float m)
    {
        if (m > limit) return;
        bill += m;
        limit -= (int)m;
        CCreditCard::points += (int)m;
    }

    void refund(float m)
    {
        bill -= m;
        CCreditCard::points -= (int)m;
    }

    void convert(int m)
    {
        CMembership::points += m / 2;
        CCreditCard::points -= m;
    }

    void print()
    {
        cout << CMembership::card_no << " " << CMembership::points << endl;
        cout << CCreditCard::card_no << " " << name << " "
             << bill << " " << CCreditCard::points << endl;
    }
};

int main()
{
    int mem_no, cred_no, limit;
    string name;
    cin >> mem_no >> cred_no >> name >> limit;
    CTravelCreditCard card(mem_no, cred_no, name, limit);
    int n;
    cin >> n;
    while (n--)
    {
        char op;
        cin >> op;
        if (op == 'o' || op == 'c' || op == 'q')
        {
            float m;
            cin >> m;
            if (op == 'o') card.order(m);
            else if (op == 'c') card.consume(m);
            else card.refund(m);
        }
        else if (op == 't')
        {
            int m;
            cin >> m;
            card.convert(m);
        }
    }
    card.print();
    return 0;
}

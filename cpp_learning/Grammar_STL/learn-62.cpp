// 练习分数类CFraction，求最大公约数、化简与四则运算
#include <iostream>
#include <cstdlib>
using namespace std;

class CFraction {
private:
    int fz, fm;
public:
    CFraction(int fz_val, int fm_val) : fz(fz_val), fm(fm_val) {}

    int getGCD() {
        int a = abs(fz), b = abs(fm);
        if (a == 0) return b;
        if (a < b) swap(a, b);
        while (b != 0) {
            int r = a % b;
            a = b;
            b = r;
        }
        return a;
    }

    void simplify() {
        if (fm < 0) { fz = -fz; fm = -fm; }
        int g = getGCD();
        if (g != 0) { fz /= g; fm /= g; }
    }

    CFraction add(const CFraction &r) {
        CFraction res(fz * r.fm + r.fz * fm, fm * r.fm);
        res.simplify();
        return res;
    }

    CFraction sub(const CFraction &r) {
        CFraction res(fz * r.fm - r.fz * fm, fm * r.fm);
        res.simplify();
        return res;
    }

    CFraction mul(const CFraction &r) {
        CFraction res(fz * r.fz, fm * r.fm);
        res.simplify();
        return res;
    }

    CFraction div(const CFraction &r) {
        CFraction res(fz * r.fm, fm * r.fz);
        res.simplify();
        return res;
    }

    void print() {
        cout << fz << "/" << fm << endl;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int fz1, fm1, fz2, fm2;
        char slash;
        cin >> fz1 >> slash >> fm1;
        cin >> fz2 >> slash >> fm2;
        CFraction a(fz1, fm1), b(fz2, fm2);
        a.add(b).print();
        a.sub(b).print();
        a.mul(b).print();
        a.div(b).print();
        std::cout<<'\n';
    }
    return 0;
}

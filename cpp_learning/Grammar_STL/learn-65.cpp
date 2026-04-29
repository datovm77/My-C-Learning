// 练习构造函数类型，默认构造、参数化构造与拷贝构造
#include <iostream>
using namespace std;

class MyClass {
private:
    int value;

public:
    MyClass() : value(0) {
        cout << "Constructed by default, value = " << value << endl;
    }

    MyClass(int v) : value(v) {
        cout << "Constructed using one argument constructor, value = " << value << endl;
    }

    MyClass(const MyClass& other) : value(other.value) {
        cout << "Constructed using copy constructor, value = " << value << endl;
    }
};

int main() {
    int t;
    cin >> t;

    while (t--) {
        int type;
        cin >> type;

        if (type == 0) {
            MyClass obj;

        } else if (type == 1) {
            int val;
            cin >> val;
            MyClass obj(val);

        } else if (type == 2) {
            int val;
            cin >> val;
            MyClass obj1(val);
            MyClass obj2(obj1);
        }
    }

    return 0;
}

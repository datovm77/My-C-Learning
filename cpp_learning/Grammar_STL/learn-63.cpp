#include<iostream>
using namespace std;
//test
class Stack {
private:
    int* a;
    int size;
    int top;
public:
    Stack() {
        size = 10;
        a = new int[size];
        top = 0;
        cout << "Constructor." << endl;
    }
    Stack(int s) {
        size = s;
        a = new int[size];
        top = 0;
        cout << "Constructor." << endl;
    }
    ~Stack() {
        delete[] a;
        cout << "Destructor." << endl;
    }
    bool isEmpty() { return top == 0; }
    bool isFull() { return top == size; }
    void push(int val) {
        if (!isFull()) {
            a[top] = val;
            top++;
        }
    }
    int pop() {
        top--;
        return a[top];
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int s;
        cin >> s;
        Stack st(s);
        for (int i = 0; i < s; i++) {
            int val;
            cin >> val;
            st.push(val);
        }
        bool first = true;
        while (!st.isEmpty()) {
            if (!first) cout << " ";
            cout << st.pop();
            first = false;
        }
        cout << endl;
    }
    return 0;
}
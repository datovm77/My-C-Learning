#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

struct ArrayStack {
    int data[MAX_SIZE];
    int top;
};

void InitStack(ArrayStack &S) {
    S.top = -1;
}

bool IsEmpty(const ArrayStack &S) {
    return S.top == -1;
}

bool IsFull(const ArrayStack &S) {
    return S.top == MAX_SIZE - 1;
}

bool Push(ArrayStack &S, int x) {
    if (IsFull(S)) {
        cout << "Stack is full. Push failed." << endl;
        return false;
    }

    S.data[++S.top] = x;
    return true;
}

bool Pop(ArrayStack &S, int &x) {
    if (IsEmpty(S)) {
        cout << "Stack is empty. Pop failed." << endl;
        return false;
    }

    x = S.data[S.top--];
    return true;
}

bool GetTop(const ArrayStack &S, int &x) {
    if (IsEmpty(S)) {
        cout << "Stack is empty. GetTop failed." << endl;
        return false;
    }

    x = S.data[S.top];
    return true;
}

int main() {
    ArrayStack S;
    InitStack(S);

    cout << "Is the stack empty? "
         << (IsEmpty(S) ? "Yes" : "No") << endl;

    Push(S, 10);
    Push(S, 20);
    Push(S, 30);
    cout << "Pushed: 10, 20, 30" << endl;

    int value;

    if (GetTop(S, value)) {
        cout << "Top element: " << value << endl;
    }

    if (Pop(S, value)) {
        cout << "Popped element: " << value << endl;
    }

    if (GetTop(S, value)) {
        cout << "Top element after pop: " << value << endl;
    }

    while (Pop(S, value)) {
        cout << "Popped element: " << value << endl;
    }

    cout << "Is the stack empty? "
         << (IsEmpty(S) ? "Yes" : "No") << endl;

    return 0;
}

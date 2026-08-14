#include <iostream>

using namespace std;

struct Node {
    int data;
    Node *next;
};

struct LinkedStack {
    Node *top;
};

void InitStack(LinkedStack &S) {
    S.top = nullptr;
}

bool IsEmpty(const LinkedStack &S) {
    return S.top == nullptr;
}

bool Push(LinkedStack &S, int x) {
    Node *newNode = new Node;
    newNode->data = x;
    newNode->next = S.top;
    S.top = newNode;

    return true;
}

bool Pop(LinkedStack &S, int &x) {
    if (IsEmpty(S)) {
        cout << "Stack is empty. Pop failed." << endl;
        return false;
    }

    Node *temp = S.top;
    x = temp->data;
    S.top = temp->next;
    delete temp;

    return true;
}

bool GetTop(const LinkedStack &S, int &x) {
    if (IsEmpty(S)) {
        cout << "Stack is empty. GetTop failed." << endl;
        return false;
    }

    x = S.top->data;
    return true;
}

void DestroyStack(LinkedStack &S) {
    while (!IsEmpty(S)) {
        Node *temp = S.top;
        S.top = S.top->next;
        delete temp;
    }
}

int main() {
    LinkedStack S;
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

    while (!IsEmpty(S)) {
        Pop(S, value);
        cout << "Popped element: " << value << endl;
    }

    cout << "Is the stack empty? "
         << (IsEmpty(S) ? "Yes" : "No") << endl;

    Push(S, 40);
    Push(S, 50);
    DestroyStack(S);

    cout << "Is the stack empty after DestroyStack? "
         << (IsEmpty(S) ? "Yes" : "No") << endl;

    return 0;
}

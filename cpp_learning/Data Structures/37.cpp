#include <iostream>
#include <stack>
#include <string>

using namespace std;

string ReverseString(const string &text) {
    stack<char> charStack;

    for (char ch : text) {
        charStack.push(ch);
    }

    string result;

    while (!charStack.empty()) {
        result += charStack.top();
        charStack.pop();
    }

    return result;
}

struct Node {
    int data;
    Node *next;
};

Node *CreateList(const int values[], int size) {
    Node *head = nullptr;
    Node *tail = nullptr;

    for (int i = 0; i < size; i++) {
        Node *newNode = new Node{values[i], nullptr};

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

void PrintList(const Node *head) {
    const Node *current = head;

    while (current != nullptr) {
        cout << current->data;
        if (current->next != nullptr) {
            cout << " -> ";
        }
        current = current->next;
    }

    cout << " -> nullptr" << endl;
}

void DestroyList(Node *&head) {
    while (head != nullptr) {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

void ReverseLinkedListUsingStack(Node *&head) {
    if (head == nullptr) {
        return;
    }

    stack<Node *> nodeStack;
    Node *current = head;

    while (current != nullptr) {
        nodeStack.push(current);
        current = current->next;
    }

    Node *newHead = nodeStack.top();
    nodeStack.pop();
    current = newHead;

    while (!nodeStack.empty()) {
        current->next = nodeStack.top();
        nodeStack.pop();
        current = current->next;
    }

    current->next = nullptr;
    head = newHead;
}

int main() {
    string text = "STACK";
    cout << "Original string: " << text << endl;
    cout << "Reversed string: " << ReverseString(text) << endl;

    int values[] = {10, 20, 30, 40};
    int size = sizeof(values) / sizeof(values[0]);
    Node *head = CreateList(values, size);

    cout << "Original list: ";
    PrintList(head);

    ReverseLinkedListUsingStack(head);

    cout << "Reversed list: ";
    PrintList(head);

    DestroyList(head);
    return 0;
}

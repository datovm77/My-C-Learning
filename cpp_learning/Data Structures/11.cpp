// 练习使用全局头尾指针尾插单链表，知识点：first头指针、last尾指针、持续尾插
#include <iostream>

struct Node {
    int data;
    Node* next;

    explicit Node(int val) : data(val), next(nullptr) {}
};

Node* first = nullptr;
Node* last = nullptr;

void insertLast(int x) {
    Node* t = new Node(x);

    if (first == nullptr) {
        first = last = t;
    } else {
        last->next = t;
        last = t;
    }
}

void display() {
    Node* curr = first;
    while (curr != nullptr) {
        std::cout << curr->data << " -> ";
        curr = curr->next;
    }
    std::cout << "NULL" << std::endl;
}

void deleteList() {
    while (first != nullptr) {
        Node* temp = first;
        first = first->next;
        delete temp;
    }

    last = nullptr;
}

int main() {
    insertLast(10);
    insertLast(20);
    insertLast(30);
    insertLast(40);
    insertLast(50);

    std::cout << "尾插法创建的链表: ";
    display();

    deleteList();
    return 0;
}

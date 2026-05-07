#include <iostream>

struct Node {
    int data;
    Node* next;
    Node(int val) : data(val), next(nullptr) {}
};

void display(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        std::cout << curr->data << " -> ";
        curr = curr->next;
    }
    std::cout << "NULL" << std::endl;
}

int main() {
    // 手动构建链表: 10 -> 20 -> 30 -> NULL
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    display(head);  // 输出: 10 -> 20 -> 30 -> NULL

    // 释放内存
    Node* curr = head;
    while (curr != nullptr) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }

    return 0;
}

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

Node* createFromArray(const int arr[], int size) {
    if (size == 0) return nullptr;
    
    Node* head = new Node(arr[0]);
    Node* tail = head;
    
    for (int i = 1; i < size; i++) {
        Node* newNode = new Node(arr[i]);
        tail->next = newNode;
        tail = newNode;
    }
    
    return head;
}

// 释放链表内存
void deleteList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }
}

int main() {
    // 用数组创建链表
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;
    
    Node* head = createFromArray(arr, size);
    
    std::cout << "链表内容: ";
    display(head);  // 输出: 10 -> 20 -> 30 -> 40 -> 50 -> NULL
    
    deleteList(head);
    
    return 0;
}
#include <iostream>

struct Node {
    int data;
    Node* next;

    explicit Node(int val) : data(val), next(nullptr) {}
};

void display(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        std::cout << curr->data << " -> ";
        curr = curr->next;
    }
    std::cout << "NULL" << std::endl;
}

void deleteList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

Node* createListByHeadInsertion(int arr[], int n) {
    Node* head = nullptr;

    for (int i = 0; i < n; i++) {
        Node* newNode = new Node(arr[i]);
        newNode->next = head;   // 新节点指向原来的头
        head = newNode;          // 更新 head
    }

    return head;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;

    Node* head = createListByHeadInsertion(arr, size);

    std::cout << "头插法创建的链表: ";
    display(head);

    deleteList(head);
    return 0;
}

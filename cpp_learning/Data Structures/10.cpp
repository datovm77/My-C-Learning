// 练习尾插法从数组创建单链表，知识点：head头指针、tail尾指针、函数返回链表头
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

// 使用尾插法，从数组创建链表
// 返回链表的头指针
Node* createListByTailInsertion(const int arr[], int n) {
    if (n <= 0) return nullptr;

    Node* head = new Node(arr[0]);
    Node* tail = head;

    for (int i = 1; i < n; i++) {
        Node* newNode = new Node(arr[i]);
        tail->next = newNode;   // 尾节点指向新节点
        tail = newNode;         // 更新 tail
    }

    return head;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;

    Node* head = createListByTailInsertion(arr, size);

    std::cout << "尾插法创建的链表: ";
    display(head);

    deleteList(head);
    return 0;
}

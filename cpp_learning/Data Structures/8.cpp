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

void deleteList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

Node* insertAtPosition(Node* head, int pos, int val) {
    if (pos < 0) {
        std::cout << "位置不能为负数" << std::endl;
        return head;
    }

    Node* newNode = new Node(val);

    // 特殊情况：在头部插入（pos == 0）
    if (pos == 0) {
        newNode->next = head;
        return newNode;   // 新节点成为新的 head
    }

    // 一般情况：找到第 pos-1 个节点（前驱节点）
    Node* prev = head;
    for (int i = 0; i < pos - 1; i++) {
        if (prev == nullptr) {
            // pos 超出链表长度，插入失败
            std::cout << "位置 " << pos << " 超出链表范围" << std::endl;
            delete newNode;
            return head;
        }
        prev = prev->next;
    }

    // 检查 prev 是否为空（pos 刚好比长度大 1 的情况）
    if (prev == nullptr) {
        std::cout << "位置 " << pos << " 超出链表范围" << std::endl;
        delete newNode;
        return head;
    }

    // 核心操作：先让新节点接住后半段，再改前驱指向
    newNode->next = prev->next;   // 步骤 1：新节点连上后面的链
    prev->next = newNode;          // 步骤 2：前驱连上新节点

    return head;
}

int main() {
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;

    Node* head = createFromArray(arr, size);

    std::cout << "原链表: ";
    display(head);

    head = insertAtPosition(head, 2, 25);
    std::cout << "在位置 2 插入 25 后: ";
    display(head);

    head = insertAtPosition(head, 0, 5);
    std::cout << "在头部插入 5 后: ";
    display(head);

    deleteList(head);
    return 0;
}

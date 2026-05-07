#include <climits>
#include <iostream>

struct Node {
    int data;
    Node* next;

    explicit Node(int val) : data(val), next(nullptr) {}
};

int findMaxRecursive(Node* curr) {
    if (curr == nullptr) {
        return INT_MIN;  // 基准情况：空节点返回最小整数
    }

    int restMax = findMaxRecursive(curr->next);  // 后面节点的最大值
    // 返回当前节点的值和后续最大值中更大的那个
    return (curr->data > restMax) ? curr->data : restMax;
}

void freeList(Node* head) {
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    std::cout << "Max value: " << findMaxRecursive(head) << '\n';

    freeList(head);
    return 0;
}

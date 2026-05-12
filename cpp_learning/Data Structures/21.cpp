// 练习反转单链表（通过反转指针指向），知识点：三指针遍历、pre/curr/next指针重连
#include <iostream>

struct Node
{
    int data;
    Node *next;

    explicit Node(int val) : data(val), next(nullptr) {}
};

void display(Node *head)
{
    Node *curr = head;
    while (curr != nullptr)
    {
        std::cout << curr->data << " -> ";
        curr = curr->next;
    }
    std::cout << "NULL" << std::endl;
}

Node *createFromArray(const int arr[], int size)
{
    if (size == 0)
        return nullptr;

    Node *head = new Node(arr[0]);
    Node *tail = head;

    for (int i = 1; i < size; i++)
    {
        Node *newNode = new Node(arr[i]);
        tail->next = newNode;
        tail = newNode;
    }

    return head;
}

void deleteList(Node *head)
{
    while (head != nullptr)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
    }
}

Node *reverse_link(Node *head)
{
    Node *pre = nullptr;
    Node *curr = head;

    while (curr != nullptr)
    {
        Node *next = curr->next;
        curr->next = pre;
        pre = curr;
        curr = next;
    }
    return pre;
}

Node *reverse_link2(Node *head)
{
    Node *pre = nullptr;
    Node *curr = nullptr;
    Node *next = head;
    while (next != nullptr)
    {
        pre = curr;
        curr = next;
        next = next->next;
        curr->next = pre;
    }
    return curr;
}
int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;

    Node *head = createFromArray(arr, size);

    std::cout << "原链表: ";
    display(head);

    std::cout << "反转链表后";
    Node *new_head = reverse_link2(head);
    display(new_head);

    deleteList(new_head);
    return 0;
}

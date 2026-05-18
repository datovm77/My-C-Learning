// 练习链表拼接与多种反转，知识点：concatenate拼接尾部、三指针反转、递归反转
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

Node *reverse_link3(Node *head)
{
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *new_head = reverse_link3(head->next);
    head->next->next = head;
    head->next = nullptr;

    return new_head;
}

Node *concatenate(Node *headA, Node *headB)
{
    if (headA == nullptr)
        return headB;

    if (headB == nullptr)
        return headA;

    Node *tail = headA;
    while (tail->next != nullptr)
    {
        tail = tail->next;
    }
    tail->next = headB;
    return headA;
}
int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;

    Node *head1 = createFromArray(arr, size);

    int arr2[] = {100, 200, 300, 400, 500};
    Node *head2 = createFromArray(arr2, size);

    Node *head_new = concatenate(head1, head2);
    display(head_new);
    return 0;
}

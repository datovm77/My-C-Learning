// 练习有序链表归并与多种反转，知识点：mergeSorted归并、三指针反转、递归反转、concatenate拼接
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

Node *mergeSorted(Node *headA, Node *headB)
{
    if (headA == nullptr)
        return headB;
    if (headB == nullptr)
        return headA;

    Node *resultHead = nullptr; // 结果链表的头
    Node *resultTail = nullptr; // 结果链表的尾
    Node *p = headA;
    Node *q = headB;

    if (p->data >= q->data)
    {
        resultHead = resultTail = q;
        q = q->next;
    }
    else
    {
        resultHead = resultTail = p;
        p = p->next;
    }

    while (p != nullptr && q != nullptr)
    {
        if (p->data >= q->data)
        {
            resultTail->next = q;
            resultTail = q;
            q = q->next;
            resultTail->next = nullptr;
        }
        else
        {
            resultTail->next = p;
            resultTail = p;
            p = p->next;
            resultTail->next = nullptr;
        }
    }

    resultTail->next = (p != nullptr) ? p : q;
    return resultHead;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;

    Node *head1 = createFromArray(arr, size);

    int arr2[] = {15, 25, 35, 45, 55};
    Node *head2 = createFromArray(arr2, size);

    Node *head_new = mergeSorted(head1, head2);
    display(head_new);

    return 0;
}

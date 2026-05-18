// 练习链表环检测与归并，知识点：Floyd判环算法hasCycle、有序链表归并mergeSorted、递归反转
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

bool hasCycle(Node *head)
{
    if (head == nullptr || head->next == nullptr)
        return false;

    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;       // 慢指针走 1 步
        fast = fast->next->next; // 快指针走 2 步
        if (slow == fast)
            return true; // 相遇，有环
    }

    return false; // fast 到达 NULL，无环
}
Node *createCyclicList()
{
    Node *n1 = new Node(10);
    Node *n2 = new Node(20);
    Node *n3 = new Node(30);
    Node *n4 = new Node(40);
    Node *n5 = new Node(50);
    n1->next = n2;
    n2->next = n3;
    n3->next = n4;
    n4->next = n5;
    n5->next = n2; // 形成环
    return n1;
}
int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;

    Node *head1 = createFromArray(arr, size);

    int arr2[] = {15, 25, 35, 45, 55};
    Node *head2 = createFromArray(arr2, size);

    Node *cycle_head = createCyclicList();
    bool result = hasCycle(cycle_head);

    if (result)
        std::cout << "为循环列表" << '\n';
    else
        std::cout << "不是循环列表" << '\n';
    return 0;
}

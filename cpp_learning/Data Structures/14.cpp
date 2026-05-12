// 练习反转单链表（通过反转元素值），知识点：数组暂存数据、双指针覆盖、动态数组new/delete
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

void reverse_link(Node *head, int size)
{
    if (size <= 0)
    {
        std::cerr << "size 必须大于 0" << std::endl;
        return;
    }

    Node *first = head;
    // int arr[size]; // 错误原因：这是变长数组(VLA)，不属于标准 C++，可移植性差且可能编译失败。
    int *arr = new int[size];
    int i = 0;
    while (first != nullptr && i < size)
    {
        arr[i] = first->data;
        i++;
        first = first->next;
    }

    if (first != nullptr)
    {
        std::cerr << "size 小于链表长度，存在越界风险" << std::endl;
        delete[] arr;
        return;
    }

    first = head;
    while (i--)
    {
        first->data = arr[i];
        first = first->next;
    }
    delete[] arr;
}

int main()
{
    int arr[] = {10, 20, 30, 40, 50};
    int size = 5;

    Node *head = createFromArray(arr, size);

    std::cout << "原链表: ";
    display(head);

    std::cout << "反转链表后";
    reverse_link(head, size);
    display(head);

    deleteList(head);
    return 0;
}

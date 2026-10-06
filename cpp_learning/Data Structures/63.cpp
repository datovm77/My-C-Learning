#include <iostream>

struct ListNode
{
    int data;
    ListNode *next = nullptr;

    explicit ListNode(int value) : data(value) {}
};

// La、Lb 指向两个递增有序链表的首元结点。
// 返回合并后的首元结点，直接复用原结点，不申请新的数据结点。
ListNode *LL_merge(ListNode *La, ListNode *Lb)
{
    ListNode dummy(0);
    ListNode *tail = &dummy;

    while (La && Lb)
    {
        if (La->data <= Lb->data)
        {
            tail->next = La;
            La = La->next;
        }
        else
        {
            tail->next = Lb;
            Lb = Lb->next;
        }
        tail = tail->next;
    }

    tail->next = La ? La : Lb;
    return dummy.next;
}

int main()
{
    int n, m;
    if (!(std::cin >> n))
    {
        return 0;
    }

    auto readList = [](int count) {
        ListNode *head = nullptr;
        ListNode *tail = nullptr;

        for (int i = 0; i < count; ++i)
        {
            int value;
            std::cin >> value;
            ListNode *node = new ListNode(value);

            if (!head)
            {
                head = node;
            }
            else
            {
                tail->next = node;
            }
            tail = node;
        }
        return head;
    };

    ListNode *La = readList(n);
    std::cin >> m;
    ListNode *Lb = readList(m);
    ListNode *merged = LL_merge(La, Lb);

    bool first = true;
    for (ListNode *p = merged; p; p = p->next)
    {
        if (!first)
        {
            std::cout << ' ';
        }
        std::cout << p->data;
        first = false;
    }
    std::cout << '\n';

    while (merged)
    {
        ListNode *next = merged->next;
        delete merged;
        merged = next;
    }
    return 0;
}

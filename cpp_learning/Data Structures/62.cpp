#include <iostream>

class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode() { next = NULL; }
};
// 带头结点的单链表类定义
class LinkList
{
public:
    ListNode *head;
    int len;
    // 操作定义
    LinkList();
    ~LinkList();
    ListNode *LL_index(int i);      // 返回第i个结点的指针，如果不存在返回NULL
    int LL_get(int i);              // 获取第i个元素的数据
    int LL_insert(int i, int item); // 把数值item插入第i个位置
    int LL_del(int i);              // 删除第i个结点
    void LL_display();              // 输出单链表的内容
};

ListNode *LinkList::LL_index(int i)
{
    if (i < 1 || i > len)
    {
        return nullptr;
    }
    ListNode *head_temp = head;
    while (i--)
    {
        head_temp = head_temp->next;
    }
    return head_temp;
}
int LinkList::LL_del(int i)
{
    if (i < 1 || i > len)
    {
        return -1;
    }
    i--;
    ListNode *head_temp = head;
    while (i--)
    {
        head_temp = head_temp->next;
    }
    ListNode *newnode = head_temp->next;
    head_temp->next = newnode->next; // 修复：原为 newnode->next = newnode->next，自己赋自己没断链，应让前驱跳过被删节点
    delete newnode;
    len--; // 修复：删除后链表长度减1，否则后续边界判断全部失效
    return 0;
}
int LinkList::LL_get(int i)
{
    if (i < 1 || i > len)
    {
        return -1;
    }
    ListNode *head_temp = head;
    while (i--)
    {
        head_temp = head_temp->next;
    }
    return head_temp->data;
}
int LinkList::LL_insert(int i, int item)
{
    // 错误代码: if (i < 1 || i > len)  —— 说明: 插入位置合法范围是[1, len+1],
    // 写成 i > len 会导致尾插(如len=3时插第4个位置)和空表插第1个位置永远报error
    if (i < 1 || i > len + 1)
    {
        return -1;
    }
    i--;
    ListNode *head_temp = head;
    while (i--)
    {
        head_temp = head_temp->next;
    }
    ListNode *newnode = new ListNode();
    newnode->data = item;
    newnode->next = head_temp->next;
    head_temp->next = newnode;
    len++;
    return 0;
}
LinkList::LinkList()
{
    head = new ListNode();
    len = 0;
}
LinkList::~LinkList()
{
    ListNode *p, *q;
    p = head;
    while (p != NULL)
    {
        q = p;
        p = p->next;
        delete q;
    }
    len = 0;
    head = NULL;
}
void LinkList::LL_display()
{
    ListNode *p;
    p = head->next;
    while (p)
    {
        // 错误写法：std::cout << p->data << ' ';
        // 说明：这样最后一个数据后面也会多输出一个空格。
        if (p != head->next)
        {
            std::cout << ' ';
        }
        std::cout << p->data;
        p = p->next;
    }
    std::cout << std::endl;
}
ListNode *LL_merge(ListNode *La, ListNode *Lb)
{
    // 错误风险：直接访问 La->next、Lb->next，但没有判断 La、Lb 是否为空。
    // 说明：调用者传入空指针时会发生段错误。
    if (La == nullptr || Lb == nullptr)
    {
        return nullptr;
    }

    // 错误写法：
    // if ((La->next == nullptr) && (Lb->next == nullptr)) return nullptr;
    // 说明：两个合法空链表合并时返回 nullptr，main 会把它当成 error 输出；
    // 当前实现保留一个空的头结点，让空链表合并结果仍然是一个正常链表。
    ListNode *new_list_move = new ListNode();
    ListNode *new_head = new_list_move;

    while ((La->next != nullptr) && (Lb->next != nullptr))
    {
        if (La->next->data <= Lb->next->data)
        {
            ListNode *temp = new ListNode;
            temp->data = La->next->data;
            new_list_move->next = temp;
            new_list_move = new_list_move->next;
            La = La->next;
        }
        else
        {
            ListNode *temp = new ListNode;
            temp->data = Lb->next->data;
            new_list_move->next = temp;
            new_list_move = new_list_move->next;
            Lb = Lb->next;
        }
    }
    while (La->next != nullptr)
    {
        ListNode *temp = new ListNode;
        temp->data = La->next->data;
        new_list_move->next = temp;
        La = La->next;
        new_list_move = new_list_move->next;
    }
    while (Lb->next != nullptr)
    {
        ListNode *temp = new ListNode;
        temp->data = Lb->next->data;
        new_list_move->next = temp;
        Lb = Lb->next;
        new_list_move = new_list_move->next;
    }

    return new_head;
}
int main()
{
    int n;
    LinkList *L1 = new LinkList();
    ListNode *head1_temp = L1->head;
    if (!(std::cin >> n) || n < 0)
    {
        // 错误风险：不检查输入，输入失败时 n 可能没有有效值；n<0 时 while(n--) 会异常循环。
        delete L1;
        return 1;
    }

    while (n--)
    {
        ListNode *temp = new ListNode();
        if (!(std::cin >> temp->data))
        {
            // 错误风险：不判断数据输入是否成功，temp->data 可能保持未初始化状态。
            delete temp;
            delete L1;
            return 1;
        }
        head1_temp->next = temp;

        head1_temp = head1_temp->next;
        L1->len++;
    }

    int n2;
    LinkList *L2 = new LinkList();
    ListNode *head2_temp = L2->head;
    if (!(std::cin >> n2) || n2 < 0)
    {
        // 错误风险：不检查第二个链表的结点数，可能导致异常循环或使用无效输入。
        delete L1;
        delete L2;
        return 1;
    }
    while (n2--)
    {
        ListNode *temp = new ListNode();
        if (!(std::cin >> temp->data))
        {
            // 错误风险：输入数据不足或不是整数时，继续使用 temp->data 会产生未定义行为。
            delete temp;
            delete L1;
            delete L2;
            return 1;
        }
        head2_temp->next = temp;
        head2_temp = head2_temp->next;
        L2->len++;
    }

    ListNode *newNode = LL_merge(L1->head, L2->head);

    // 错误写法：L1->head = nullptr; L2->head = nullptr;
    // 说明：这样 delete L1、delete L2 时，析构函数找不到原链表结点，
    // 会造成两个原链表的头结点和数据结点全部内存泄漏。

    LinkList *newList = new LinkList();
    // 错误风险：直接覆盖 newList->head 会泄漏构造函数申请的原头结点。
    delete newList->head;
    newList->head = newNode;
    newList->len = L1->len + L2->len;

    if (newNode == nullptr)
    {
        // LL_merge 只有在传入空指针时才会返回 nullptr。
        // 两个合法空链表会返回一个空的头结点，因此这里不输出 error。
        std::cout << std::endl;
    }
    else
    {
        newList->LL_display();
    }

    delete newList;
    delete L1;
    delete L2;
    return 0;
}

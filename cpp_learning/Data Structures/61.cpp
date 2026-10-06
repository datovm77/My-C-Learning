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
    head_temp->next = newnode->next;  // 修复：原为 newnode->next = newnode->next，自己赋自己没断链，应让前驱跳过被删节点
    delete newnode;
    len--;  // 修复：删除后链表长度减1，否则后续边界判断全部失效
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
        std::cout << p->data << ' ';
        p = p->next;
    }
    std::cout << std::endl;
}

int main()
{
    int n;
    std::cin >> n;
    LinkList *p = new LinkList();
    ListNode *head_temp = p->head;

    while (n--)
    {
        ListNode *newnode = new ListNode();
        head_temp->next = newnode;
        std::cin >> head_temp->next->data;
        head_temp = head_temp->next;
        p->len++;
    }
    p->LL_display();

    int i, item;
    std::cin >> i >> item;
    int flag1 = p->LL_insert(i, item);
    if (flag1 == -1)
    {
        std::cout << "error" << '\n';
    }
    else
    {
        p->LL_display();
    }

    int i2, item2;
    std::cin >> i2 >> item2;
    int flag2 = p->LL_insert(i2, item2);
    if (flag2 == -1)
    {
        std::cout << "error" << '\n';
    }
    else
    {
        p->LL_display();
    }

    int d1, d2;
    std::cin >> d1 >> d2;
    int flag3 = p->LL_del(d1);
    if (flag3 == -1)
    {
        std::cout << "error" << '\n';
    }
    else
    {
        p->LL_display();
    }

    int flag4 = p->LL_del(d2);
    if (flag4 == -1)
    {
        std::cout << "error" << '\n';
    }
    else
    {
        p->LL_display();
    }

    int f1, f2;
    std::cin >> f1 >> f2;
    // 错误代码: int flag5 = p->LL_get(f1); if (flag5 == -1) 输出error
    // 说明: LL_get成功时返回的是结点数据, 若数据本身就是-1会与失败标志-1混淆而误判;
    // 正确做法是先用 LL_index判空(位置是否合法), 合法再取值输出
    if (p->LL_index(f1) == NULL)
    {
        std::cout << "error" << '\n';
    }
    else
    {
        std::cout << p->LL_get(f1) << '\n';
    }

    if (p->LL_index(f2) == NULL)
    {
        std::cout << "error" << '\n';
    }
    else
    {
        std::cout << p->LL_get(f2) << '\n';
    }
}
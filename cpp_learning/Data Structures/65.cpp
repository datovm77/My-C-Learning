#include <iostream>
#include <string>
struct LinkNode
{
    char data;
    LinkNode *pre;
    LinkNode *next;

    LinkNode(char data) : data(data), pre(nullptr), next(nullptr) {}
};

LinkNode *insert(int location, char C, LinkNode *S)
{
    LinkNode *node = new LinkNode(C);
    if (location == 0)
    {
        node->next = S;
        if (S != nullptr)
            S->pre = node;
        S = node;
        return S;
    }

    // 原错误代码(已注释掉):
    // LinkNode *current = S;
    // for (int i = 0; i < location; i++) current = current->next;
    // else if (current->next == nullptr) { node->pre = current; current->next = node; }
    // 说明: 这样current指向“原index==location的节点”。
    // 错1:k==m尾插时current==nullptr，current->next直接崩;
    // 错2:k==m-1插倒数第二个前面时current是尾节点，被误判为追加，结果插到最后。
    // 修正: 统一找前驱( index==location-1 )，往后面插，一种写法覆盖中间/次尾/尾插。
    LinkNode *cur = S;
    for (int i = 0; i < location - 1; i++)
    {
        cur = cur->next;
    }
    node->next = cur->next;
    node->pre = cur;
    if (cur->next != nullptr)
        cur->next->pre = node;
    cur->next = node;
    return S;
}

// 删除 [start..end] 整段，返回新头
static LinkNode *eraseSegment(LinkNode *S, LinkNode *start, LinkNode *end)
{
    LinkNode *L = start->pre;
    LinkNode *R = end->next;
    if (L == nullptr && R == nullptr)
    {
        S = nullptr;
    }
    else if (L == nullptr)
    {
        S = R;
        R->pre = nullptr;
    }
    else if (R == nullptr)
    {
        // 原错误代码(已注释掉):
        // temp->next->pre = nullptr;
        // 说明: 该分支是删尾段，此时temp->next就是nullptr，对空指针解引用必崩。
        // 修正: 删尾段只需 L->next = nullptr。
        L->next = nullptr;
    }
    else
    {
        L->next = R;
        R->pre = L;
    }
    LinkNode *p = start;
    while (p != R)
    {
        LinkNode *del = p;
        p = p->next;
        delete del;
    }
    return S;
}

LinkNode *xiaochu(LinkNode *S)
{
    // 原错误代码(已注释掉):
    // char t = S->data;
    // 说明: S为空时解引用崩。插入后一般非空，但全消后重进仍需判空。
    // 修正: 空表直接返回。
    if (S == nullptr)
        return nullptr;

    while (true)
    {
        LinkNode *start = S;
        bool found = false;
        while (start != nullptr)
        {
            LinkNode *end = start;
            // 原错误代码(已注释掉):
            // if (temp->data == t) { count++; if (count == 3) {删[start..temp]三个;重扫} }
            // 说明: 边数边到3就切，只删3个。连锁合并会产生4连，
            // 如 AA BB AA +2 B -> AA BBB AA -> 删BBB -> AAAA，正确应整段删光，原逻辑剩1个A。
            // 修正: 先把一整段同色数完算len，若len>=3则整段删光。
            while (end->next != nullptr && end->next->data == start->data)
                end = end->next;
            int len = 0;
            for (LinkNode *q = start;; q = q->next)
            {
                len++;
                if (q == end)
                    break;
            }
            if (len >= 3)
            {
                S = eraseSegment(S, start, end);
                found = true;
                break; // 删一段后重扫，处理连锁合并
            }
            start = end->next;
        }
        if (!found)
            break;
        if (S == nullptr)
            break;
    }
    return S;
}

void display(LinkNode *S)
{
    if (S == nullptr)
    {
        std::cout << "-" << '\n';
        return;
    }
    LinkNode *temp = S;
    while (temp != nullptr)
    {
        std::cout << temp->data;
        temp = temp->next;
    }
    std::cout << '\n';
}

int main()
{
    int n;
    if (!(std::cin >> n))
        return 0;
    // 原错误写法(已注释掉，逻辑碰巧可用但难懂):
    // for (int i = 0; i < n; i++) { char c; std::cin >> c; ... }
    // 说明: cin>>char每次只读一个非空白字符，读"ACCBA"碰巧能逐个读出，但易误解。
    // 修正: 直接读整串，再按串建表。
    std::string init;
    std::cin >> init;
    LinkNode *head = nullptr;
    LinkNode *current = nullptr;
    for (size_t i = 0; i < init.size(); i++)
    {
        LinkNode *node = new LinkNode(init[i]);
        if (i == 0)
        {
            head = current = node;
        }
        else
        {
            current->next = node;
            node->pre = current;
            current = node;
        }
    }
    int t;
    std::cin >> t;
    while (t--)
    {
        int location;
        char C;
        std::cin >> location >> C;

        head = insert(location, C, head);
        head = xiaochu(head);
        display(head);
    }
    while (head != nullptr)
    {
        LinkNode *del = head;
        head = head->next;
        delete del;
    }
}

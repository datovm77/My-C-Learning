#include <iostream>

struct ListNode
{
    int data;
    ListNode *next = nullptr;
    explicit ListNode(int val) : data(val) {}
};

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t;
    if (!(std::cin >> t))
        return 0;

    while (t--)
    {
        int N, K, S;
        std::cin >> N >> K >> S;

        // 1. 构建 1 ~ N 的循环链表
        ListNode *head = new ListNode(1);
        ListNode *tail = head;
        for (int i = 2; i <= N; ++i)
        {
            tail->next = new ListNode(i);
            tail = tail->next;
        }
        tail->next = head; // 尾连头，成环

        // 2. 将指针 p 停在第 S 个人的【前一个节点】
        // tail 本身就是第 1 个人的前驱，所以从 tail 往前走 S - 1 步即可
        ListNode *p = tail;
        for (int i = 1; i < S; ++i)
        {
            p = p->next;
        }

        // 3. 淘汰 N 个人
        for (int i = 0; i < N; ++i)
        {
            // 报数到 K：当前人算第 1 个，只需再往前移动 K - 1 步
            for (int step = 1; step < K; ++step)
            {
                p = p->next;
            }

            // 此时 p->next 就是目标淘汰者
            ListNode *victim = p->next;
            std::cout << victim->data << (i == N - 1 ? "" : " ");

            // 移除并释放节点
            p->next = victim->next;
            delete victim;
        }
        std::cout << '\n';
    }

    return 0;
}
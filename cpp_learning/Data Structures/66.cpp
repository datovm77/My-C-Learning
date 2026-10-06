#include <iostream>
#include <string>

using namespace std;

// 双向链表节点
struct Node {
    char val;
    Node *prev;
    Node *next;
    Node(char v = 0) : val(v), prev(nullptr), next(nullptr) {}
};

// 祖玛双向链表管理类（带哨兵头尾节点）
class ZumaList {
private:
    Node *head; // 哨兵头节点
    Node *tail; // 哨兵尾节点
    int size;

    // 检查并执行以新节点或拼接点为中心的连锁消除
    void eliminate(Node *startLeft, Node *startRight) {
        Node *pLeft = startLeft;
        Node *pRight = startRight;

        while (pLeft != head && pRight != tail && pLeft->val == pRight->val) {
            char color = pLeft->val;

            // 向左扩展寻找相同颜色的最左边界
            while (pLeft->prev != head && pLeft->prev->val == color) {
                pLeft = pLeft->prev;
            }

            // 向右扩展寻找相同颜色的最右边界
            while (pRight->next != tail && pRight->next->val == color) {
                pRight = pRight->next;
            }

            // 统计 [pLeft, pRight] 区间内相同颜色珠子的总数量
            int count = 0;
            for (Node *p = pLeft; ; p = p->next) {
                count++;
                if (p == pRight) break;
            }

            // 只有当同色连续珠子达到 3 个或更多时才消除
            if (count >= 3) {
                Node *nextLeft = pLeft->prev;
                Node *nextRight = pRight->next;

                // 释放 [pLeft, pRight] 闭区间的所有节点
                Node *curr = pLeft;
                while (curr != nextRight) {
                    Node *nxt = curr->next;
                    delete curr;
                    curr = nxt;
                }

                // 重新连接两端
                nextLeft->next = nextRight;
                nextRight->prev = nextLeft;
                size -= count;

                // 准备检查消除后拼接处是否发生连锁反应
                pLeft = nextLeft;
                pRight = nextRight;
            } else {
                // 不满足消除条件，停止连锁反应
                break;
            }
        }
    }

public:
    ZumaList() : size(0) {
        head = new Node();
        tail = new Node();
        head->next = tail;
        tail->prev = head;
    }

    ~ZumaList() {
        Node *curr = head;
        while (curr != nullptr) {
            Node *nxt = curr->next;
            delete curr;
            curr = nxt;
        }
    }

    // 在链表末尾追加珠子（用于初始化，不触发消除）
    void push_back(char color) {
        Node *newNode = new Node(color);
        newNode->prev = tail->prev;
        newNode->next = tail;
        tail->prev->next = newNode;
        tail->prev = newNode;
        size++;
    }

    // 在位置 k 插入颜色为 color 的珠子 (0 <= k <= size)
    void insert(int k, char color) {
        // 定位到第 k 个节点（0 <= k <= size，若 k == size 则为 tail）
        Node *cur = head->next;
        for (int i = 0; i < k; ++i) {
            cur = cur->next;
        }

        // 新建节点并插入到 cur 之前
        Node *newNode = new Node(color);
        newNode->prev = cur->prev;
        newNode->next = cur;
        cur->prev->next = newNode;
        cur->prev = newNode;
        size++;

        // 插入后以该节点为中心触发消除判定
        eliminate(newNode, newNode);
    }

    // 打印当前链表状态
    void print() const {
        if (size == 0) {
            cout << "-" << "\n";
            return;
        }
        for (Node *p = head->next; p != tail; p = p->next) {
            cout << p->val;
        }
        cout << "\n";
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    if (!(cin >> n)) return 0;

    string s;
    cin >> s;

    ZumaList zuma;
    for (int i = 0; i < n; ++i) {
        zuma.push_back(s[i]);
    }

    int t;
    if (!(cin >> t)) return 0;

    while (t--) {
        int k;
        char c;
        cin >> k >> c;
        zuma.insert(k, c);
        zuma.print();
    }

    return 0;
}

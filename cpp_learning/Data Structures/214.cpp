// 小根堆（非练习）
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class MinHeap
{
private:
    // 使用 1 下标，h[0] 不存放有效元素
    vector<int> h = {0};

public:
    bool empty() const
    {
        return h.size() == 1;
    }

    int size() const
    {
        return (int)h.size() - 1;
    }

    // 插入元素
    void push(int x)
    {
        h.push_back(x);

        int i = size();

        while (i > 1 && h[i] < h[i / 2])
        {
            swap(h[i], h[i / 2]);
            i /= 2;
        }
    }

    // 查询最小值，调用前保证非空
    int top() const
    {
        return h[1];
    }

    // 删除最小值，调用前保证非空
    void pop()
    {
        if (empty())
            return;

        h[1] = h.back();
        h.pop_back();

        int i = 1;
        int n = size();

        while (i * 2 <= n)
        {
            int child = i * 2;

            // 选择两个孩子中更小的
            if (child + 1 <= n &&
                h[child + 1] < h[child])
            {
                child++;
            }

            // 当前节点已经不大于孩子
            if (h[i] <= h[child])
                break;

            swap(h[i], h[child]);
            i = child;
        }
    }
};

int main()
{
    MinHeap heap;

    heap.push(8);
    heap.push(3);
    heap.push(10);
    heap.push(5);
    heap.push(2);

    while (!heap.empty())
    {
        cout << heap.top() << " ";
        heap.pop();
    }

    return 0;
}

#include <queue>

class MyStack {
private:
    std::queue<int> q;

public:
    MyStack() {}

    void push(int x) {
        int n = q.size();
        q.push(x);
        // 将前面的 n 个元素循环移动到新元素后面
        for (int i = 0; i < n; i++) {
            q.push(q.front());
            q.pop();
        }
    }

    int pop() {
        int res = q.front();
        q.pop();
        return res;
    }

    int top() {
        return q.front();
    }

    bool empty() {
        return q.empty();
    }
};
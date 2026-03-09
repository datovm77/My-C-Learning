#include<iostream>
#include<queue>
#include <queue>
// LeetCode 225. 用队列实现栈
class MyStack {
private:
    std::queue<int> q1; // 主队列
    std::queue<int> q2; // 辅助队列

public:
    MyStack() {}

    void push(int x) {
        q2.push(x); // 新元素先入 q2
        // 将 q1 的元素全部移入 q2，使新元素排在队头
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        // 交换 q1 和 q2
        std::swap(q1, q2);
    }

    int pop() {
        int res = q1.front();
        q1.pop();
        return res;
    }

    int top() {
        return q1.front();
    }

    bool empty() {
        return q1.empty();
    }
};
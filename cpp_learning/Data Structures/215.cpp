// 小根堆（priority_queue 用法示例，非题解）
#include <iostream>
#include <queue>
#include <vector>
#include <functional>
using namespace std;

int main()
{
    // 小根堆
    priority_queue<int, vector<int>, greater<int>> pq;

    pq.push(7);
    pq.push(2);
    pq.push(9);
    pq.push(1);
    pq.push(5);

    while (!pq.empty())
    {
        cout << pq.top() << " ";
        pq.pop();
    }

    return 0;
}

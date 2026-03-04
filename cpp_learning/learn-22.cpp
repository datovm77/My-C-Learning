#include <iostream>
#include <deque>
using namespace std;

void printDeque(const deque<int> &d)
{
    for (const auto &elem : d)
    {
        cout << elem << " ";
    }
    cout << endl;
}

int main()
{
    // 1. 默认构造
    deque<int> d1;
    cout << "d1 (默认构造): ";
    printDeque(d1); // (空)

    // 2. 填充构造
    deque<int> d2(5, 100);
    cout << "d2 (5个100): ";
    printDeque(d2); // 100 100 100 100 100

    // 3. 区间构造
    deque<int> d3(d2.begin(), d2.begin() + 3);
    cout << "d3 (d2的前3个): ";
    printDeque(d3); // 100 100 100

    // 4. 拷贝构造
    deque<int> d4(d3);
    cout << "d4 (拷贝d3): ";
    printDeque(d4); // 100 100 100

    // 5. 初始化列表构造
    deque<int> d5 = {10, 20, 30, 40, 50};
    cout << "d5 (初始化列表): ";
    printDeque(d5); // 10 20 30 40 50

    // 6. 移动构造
    deque<int> d6(std::move(d5));
    cout << "d6 (移动自d5): ";
    printDeque(d6); // 10 20 30 40 50
    cout << "d5 (被移动后): ";
    printDeque(d5); // (通常为空)

    return 0;
}
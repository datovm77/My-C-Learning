// 练习deque容器的增删与访问操作，知识点：push/pop首尾操作、insert、erase、at
#include <iostream>
#include <deque>
#include <string>

void printDeque(const std::string &label, const std::deque<int> &d)
{
    std::cout << label << ": ";
    for (const auto &elem : d)
    {
        std::cout << elem << " ";
    }
    std::cout << "(size=" << d.size() << ")" << std::endl;
}

int main()
{
    std::deque<int> d;

    // === 头部和尾部操作 ===
    d.push_back(3);
    d.push_back(4);
    d.push_front(2);
    d.push_front(1);
    printDeque("push 后", d); // 1 2 3 4

    d.pop_front();
    printDeque("pop_front 后", d); // 2 3 4

    d.pop_back();
    printDeque("pop_back 后", d); // 2 3

    // === 中间插入 ===
    d.insert(d.begin() + 1, 99);
    printDeque("insert(pos1, 99)", d); // 2 99 3

    d.insert(d.end(), 3, 0);
    printDeque("insert(end, 3个0)", d); // 2 99 3 0 0 0

    d.insert(d.begin(), {-2, -1});
    printDeque("insert(begin, 列表)", d); // -2 -1 2 99 3 0 0 0

    // === 删除操作 ===
    d.erase(d.begin() + 3);       // 删除 99
    printDeque("erase(pos3)", d); // -2 -1 2 3 0 0 0

    d.erase(d.begin() + 4, d.end()); // 删除后面的 0
    printDeque("erase(区间)", d);    // -2 -1 2 3

    // === 清空 ===
    d.clear();
    printDeque("clear 后", d); // (空)

    return 0;
}

// 练习queue队列容器与银行服务模拟，知识点：queue先进先出、emplace、模拟排队
#include <iostream>
#include <queue>
#include <string>
using namespace std;

class Customer
{
public:
    string name;
    int serviceTime; // 需要的服务时间（分钟）

    Customer(string n, int t) : name(n), serviceTime(t) {}
};

int main()
{

    queue<Customer> waitingLine;

    // 顾客依次排队
    waitingLine.emplace("张三", 5);
    waitingLine.emplace("李四", 3);
    waitingLine.emplace("王五", 8);
    waitingLine.emplace("赵六", 2);

    cout << "=== 银行窗口服务模拟 ===" << endl;
    cout << "当前排队人数: " << waitingLine.size() << endl;
    cout << endl;

    int totalTime = 0;
    int customerCount = 0;

    while (!waitingLine.empty())
    {
        // 获取队头的顾客
        Customer current = waitingLine.front();
        waitingLine.pop();

        customerCount++;
        totalTime += current.serviceTime;

        cout << "第 " << customerCount << " 位顾客: " << current.name
             << "，服务时间: " << current.serviceTime << " 分钟"
             << "，剩余等待人数: " << waitingLine.size() << endl;
    }

    cout << endl;
    cout << "=== 服务结束 ===" << endl;
    cout << "共服务 " << customerCount << " 位顾客" << endl;
    cout << "总耗时: " << totalTime << " 分钟" << endl;

    return 0;
}

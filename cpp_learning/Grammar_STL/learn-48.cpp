// 练习for_each配合仿函数对象进行累加统计
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Accumulator {
public:
    int sum = 0;
    int count = 0;

    void operator()(const int &val) {
        sum += val;
        count++;
    }
};

int main() {
    vector<int> v = {10, 20, 30, 40, 50};

    // for_each 返回在内部经过遍历后的仿函数对象
    Accumulator result = for_each(v.begin(), v.end(), Accumulator());

    cout << "总和: " << result.sum << endl;      // 150
    cout << "元素个数: " << result.count << endl;  // 5
    cout << "平均值: " << (double)result.sum / result.count << endl;  // 30

    return 0;
}
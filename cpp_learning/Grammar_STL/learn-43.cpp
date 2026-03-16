#include <iostream>
#include <set>
#include <cmath>
//P5250 【深基17.例5】木材仓库
int main() {
    // 优化输入输出速度（竞赛常用）
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int m;
    if (!(std::cin >> m)) return 0;

    std::set<int> storage;

    while (m--) {
        int type, length;
        std::cin >> type >> length;

        if (type == 1) {
            // 操作 1：进货（插入木材）
            // insert 返回 pair<iterator, bool>，第二个表示是否插入成功（是否无重复）
            auto [it, success] = storage.insert(length); // C++17 结构化绑定
            
            if (!success) {
                std::cout << "Already Exist\n";
            }
        } 
        else if (type == 2) {
            // 操作 2：出货（查找并删除最接近的木材）
            if (storage.empty()) {
                std::cout << "Empty\n";
                continue;
            }

            // --- 核心逻辑：找最接近的值 ---
            
            // 1. 找到第一个 >= length 的元素
            auto it = storage.lower_bound(length);
            
            int target_val;

            // 2. 分类讨论边界情况
            if (it == storage.end()) {
                // 情况 A：所有元素都比 length 小，取集合中最大的元素
                target_val = *std::prev(it); // 等价于 *storage.rbegin()
            } 
            else if (it == storage.begin()) {
                // 情况 B：所有元素都 >= length，取集合中最小的元素
                target_val = *it;
            } 
            else {
                // 情况 C：length 落在集合中间，左右两边都有元素
                int right_val = *it;               // 右侧候选（>= length）
                int left_val = *std::prev(it);     // 左侧候选（< length）

                // 如果确实存在完全等长的，lower_bound 会直接指向它
                if (right_val == length) {
                    target_val = right_val;
                } else {
                    // 比较距离，距离相等时取较小值 (left_val)
                    if ((right_val - length) >= (length - left_val)) {
                        target_val = left_val;
                    } else {
                        target_val = right_val;
                    }
                }
            }

            // 3. 输出并从集合中移除该元素
            std::cout << target_val << '\n';
            storage.erase(target_val);
        }
    }

    return 0;
}

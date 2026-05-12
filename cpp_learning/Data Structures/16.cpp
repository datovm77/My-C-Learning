#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
class CStudent
{
    std::vector<int> stu_score;
    std::string name;
    double avr_scores = 0.00;

public:
    // CStudent(const std::vector<int> &scores, const std::string &name) { this->name = name; stu_score = scores; ... } // 不规范：构造后再赋值不如初始化列表直接构造成员
    CStudent(const std::vector<int> &scores, const std::string &name) : stu_score(scores), name(name)
    {
        // this->name = name; // 不规范：这里可由初始化列表完成赋值，避免冗余
        // stu_score = scores; // 不规范：这里可由初始化列表直接构造，效率和可读性更好
        int sum = 0;
        for (const int &x : scores)
        {
            sum += x;
        }
        // avr_scores = 1.0 * sum / scores.size(); // 不规范：未处理空数组会导致除零
        avr_scores = scores.empty() ? 0.0 : 1.0 * sum / scores.size();
    }

    void show() const
    {
        std::cout << name;
        for (const int &x : stu_score)
        {
            std::cout << " " << x;
        }
        std::cout << " " << std::fixed << std::setprecision(2) << avr_scores << '\n';
    }
    // double get_avr() // 不规范：getter 未声明为 const，不便于 const 对象调用
    double get_avr() const
    {
        return avr_scores;
    }
};

int main()
{
    std::string name = "";
    while (std::cin >> name)
    {
        int t;
        std::cin >> t;
        std::vector<int> stu_scores;
        for (int i = 0; i < t; ++i)
        {
            int insert;
            std::cin >> insert;
            stu_scores.emplace_back(insert);
        }
        CStudent stu(stu_scores, name);
        stu.show();
    }
    return 0;
}

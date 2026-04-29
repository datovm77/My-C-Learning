// 练习Hotel类静态成员，自动编号与总收入统计
#include <iostream>
#include <string>
#include <vector>
class Hotel
{
private:
    static int totalCustNum;   // 顾客总人数
    static float totalEarning; // 旅店总收入
    float rent;                // 每个顾客的房租
    std::string customerName;  // 顾客姓名
    std::string customerId;    // 顾客编号
public:
    // totalCustNum++，customerId按照totalCustNum生成
    Hotel(const std::string &str, const float &rent)
    {
        customerName = str;
        this->rent = rent;
        totalCustNum++;
        totalEarning += rent;

        std::string t_num = std::to_string(totalCustNum);
        int raw_size = static_cast<int>(t_num.size());
        if (t_num.size() < 4)
        {
            for (int i = 0; i < 4 - raw_size; i++)
            {
                t_num = "0" + t_num;
            }
        }
        customerId = "2015" + t_num;
    }
    void Display()
    {
        std::cout << customerName << " " << customerId << " " << totalCustNum << " " << totalEarning << '\n';
    }
};
int Hotel::totalCustNum = 0;
float Hotel::totalEarning = 0;

int main()
{
    float rent_num;
    std::cin >> rent_num;
    std::string str;

    while (std::cin >> str && str != "0")
    {
        Hotel h1(str, rent_num);
        h1.Display();
    }

    return 0;
}

// 练习Person类计算BMI指数与体脂率，格式化输出
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
class Person
{
public:
    std::string name;
    double height;
    double weight;
    double w_size;

    void result()
    {
        double BMI = weight / (height * height);

        int r_BMI = (BMI - int(BMI) >= 0.5) ? int(BMI) + 1 : int(BMI);

        double body_fat_per = ((w_size * 0.74) - (weight * 0.082 + 34.89)) / weight;

        std::cout << name << "的BMI指数为" << r_BMI << "--体脂率为" << std::fixed << std::setprecision(2) << body_fat_per << '\n';
    }
};

void test01()
{
    int n;
    std::cin >> n;
    for (int i = 0; i < n; ++i)
    {
        Person p;
        std::cin >> p.name >> p.height >> p.weight >> p.w_size;
        p.result();
    }
}

int main()
{
    test01();
    return 0;
}

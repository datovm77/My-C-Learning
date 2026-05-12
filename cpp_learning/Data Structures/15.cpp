// 知识点：static静态成员属于整个类，适合统计所有对象共享的总和；应在构造对象时更新。
#include <iostream>
#include <vector>
class Cvector
{
private:
    std::vector<int> vec;
    static int sum;

public:
    Cvector()
    {
    }

    Cvector(const std::vector<int> &vec_out)
    {
        vec = vec_out;
        for (size_t i = 0; i < vec.size(); ++i)
        {
            sum += vec[i];
        }
    }

    // 原错误写法：
    // int vec_sum()
    // {
    //     for (const int &x : vec)
    //     {
    //         sum += x;
    //     }
    //     return sum;
    // }
    // 错误原因：每调用一次都会把当前对象的元素重复累加一遍，
    // 题目要求是在“对象初始化时”统计总和，不应靠普通成员函数重复计算。

    static void reset_sum()
    {
        sum = 0;
    }

    static int get_sum()
    {
        return sum;
    }

    void show() const
    {
        for (size_t i = 0; i < vec.size(); ++i)
        {
            if (i > 0)
                std::cout << " ";

            std::cout << vec[i];
        }
        std::cout << '\n';
    }
};

int Cvector::sum = 0;

int main()
{
    int t;
    std::cin >> t;

    for (int i = 0; i < t; ++i)
    {
        int m;
        std::cin >> m;
        for (int j = 0; j < m; ++j)
        {
            int size;
            std::cin >> size;
            std::vector<int> temp;
            for (int t = 0; t < size; t++)
            {
                int num;
                std::cin >> num;
                temp.emplace_back(num);
            }
            Cvector v1(temp);
            v1.show();
            // 原错误写法：v1.vec_sum();
            // 错误原因：这里会把统计动作放到构造之后，且存在重复调用就重复累加的问题。
        }

        // 原错误写法：
        // Cvector v1;
        // std::cout << v1.vec_sum() << '\n';
        // v1.reset_sum();
        // 错误原因：用空对象去“取总和”只是碰巧可行，语义不对；
        // 读取和重置静态成员应通过静态成员函数完成。
        std::cout << Cvector::get_sum() << '\n';
        Cvector::reset_sum();
    }

    return 0;
}

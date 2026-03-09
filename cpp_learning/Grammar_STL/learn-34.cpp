#include <iostream>
#include <string>
#include <vector>
#include <cctype>
//P1449 后缀表达式

// 方案3：用vector模拟栈（比std::stack更灵活，便于调试查看内容）。
// 思路仍是后缀表达式经典做法，但实现层面改为手写栈接口。
class IntStack
{
public:
    void push(int x) { data_.push_back(x); }

    bool pop2(int &a, int &b)
    {
        if (data_.size() < 2)
        {
            return false;
        }
        b = data_.back();
        data_.pop_back();
        a = data_.back();
        data_.pop_back();
        return true;
    }

    bool single(int &x) const
    {
        if (data_.size() != 1)
        {
            return false;
        }
        x = data_.back();
        return true;
    }

private:
    std::vector<int> data_;
};

int main()
{
    std::string s;
    std::getline(std::cin, s);

    IntStack st;
    int current = 0;
    bool buildingNumber = false;

    auto flushNumber = [&]()
    {
        if (buildingNumber)
        {
            st.push(current);
            current = 0;
            buildingNumber = false;
        }
    };

    bool ok = true;

    for (char ch : s)
    {
        if (std::isdigit(static_cast<unsigned char>(ch)))
        {
            current = current * 10 + (ch - '0');
            buildingNumber = true;
        }
        else if (ch == '.')
        {
            flushNumber();
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            flushNumber();
            int a = 0, b = 0;
            if (!st.pop2(a, b))
            {
                ok = false;
                break;
            }
            if (ch == '+')
                st.push(a + b);
            else if (ch == '-')
                st.push(a - b);
            else if (ch == '*')
                st.push(a * b);
            else
                st.push(a / b);
        }
        else if (ch == '@')
        {
            flushNumber();
            break;
        }
    }

    int ans = 0;
    if (!ok || !st.single(ans))
    {
        std::cout << "Invalid expression\n";
        return 0;
    }

    std::cout << ans << '\n';
    return 0;
}

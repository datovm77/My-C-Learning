#include <iostream>
#include <memory>
#include <string>

class Member
{
protected:
    std::string name;
    int number;
    int score;

public:
    Member(const std::string &name, int number, int score)
        : name(name), number(number), score(score) {}
    virtual ~Member() = default;

    virtual void add(int money)
    {
        score += money;
    }

    virtual int exchange(int exchange_score)
    {
        int usable_score = exchange_score < score ? exchange_score : score;
        int money = usable_score / 100;
        score -= money * 100;
        return money;
    }

    virtual void print() const
    {
        std::cout << "普通会员" << number << "--" << name << "--" << score << '\n';
    }
};

class VIP : public Member
{
protected:
    int add_percent;
    int ex_percent;

public:
    // 旧写法：class VIP : Member。未写 public 时为私有继承，不能作为 Member 使用。
    VIP(int add_p, int ex_per, const std::string &name, int number, int score)
        : Member(name, number, score), add_percent(add_p), ex_percent(ex_per) {}

    // 旧写法：void add(VIP &m, int money)。参数类型不同，只是隐藏基类函数，不能覆盖虚函数。
    void add(int money) override
    {
        score += add_percent * money;
    }

    // 旧写法：int exchange(VIP &m, int score)。参数类型不同，不能产生运行时多态。
    int exchange(int exchange_score) override
    {
        int usable_score = exchange_score < score ? exchange_score : score;
        int money = usable_score / ex_percent;
        score -= money * ex_percent;
        return money;
    }

    void print() const override
    {
        std::cout << "贵宾会员" << number << "--" << name << "--" << score << '\n';
    }
};

int main()
{
    int number;
    std::string name;
    int score;
    int sp_money;
    int score_cost;

    std::cin >> number >> name >> score;
    std::cin >> sp_money >> score_cost;

    std::unique_ptr<Member> p = std::make_unique<Member>(name, number, score);
    p->add(sp_money);
    p->exchange(score_cost);
    p->print();

    int sum_per;
    int sco_ex;
    std::cin >> number >> name >> score >> sum_per >> sco_ex;
    std::cin >> sp_money >> score_cost;

    // 通过基类指针调用，验证 add、exchange、print 的运行时多态。
    std::unique_ptr<Member> p2 = std::make_unique<VIP>(sum_per, sco_ex, name, number, score);
    p2->add(sp_money);
    p2->exchange(score_cost);
    p2->print();

    return 0;
}

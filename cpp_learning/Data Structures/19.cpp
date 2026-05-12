#include <iostream>
#include <string>
class Person
{
private:
    std::string name = "";
    int age = 0;

public:
    void set_name_age(const std::string &name_son, int son_age)
    {
        name = name_son;
        age = son_age;
    }

    // std::string getname() // 不规范：getter 未声明为 const，不能用于 const 对象
    std::string getname() const
    {
        return name;
    }
    // int get_age() // 不规范：getter 未声明为 const，接口语义不够明确
    int get_age() const
    {
        return age;
    }
};

// class hear_free : Person // 不规范：class 默认私有继承，通常不符合“子类是父类”的建模语义
class hear_free : public Person
{
    int test_grade;
    char sum_grade;

public:
    hear_free(int t_g, int age, const std::string &name) : test_grade(t_g)
    {
        Person::set_name_age(name, age);
        double grade = 1.0 * test_grade;
        if (grade >= 85.0)
        {
            sum_grade = 'A';
        }
        else if (grade >= 75.0 && grade < 85.0)
        {
            sum_grade = 'B';
        }
        else if (grade >= 65.0 && grade < 75.0)
        {
            sum_grade = 'C';
        }
        else if (grade >= 60.0 && grade < 65.0)
        {
            sum_grade = 'D';
        }
        else
        {
            sum_grade = 'F';
        }
    }

    void show() const
    {
        std::cout << Person::getname() << " " << Person::get_age() << " " << sum_grade << '\n';
    }
};

// class no_hearing_free : Person // 不规范：默认私有继承会隐藏基类公有接口
class no_hearing_free : public Person
{
    int regular_grade;
    int test_grade;
    char sum_grade;

public:
    no_hearing_free(int r_g, int t_g, int age, const std::string &name) : regular_grade(r_g), test_grade(t_g)
    {
        Person::set_name_age(name, age);
        double grade = 0.4 * regular_grade + 0.6 * test_grade;
        if (grade >= 85.0)
        {
            sum_grade = 'A';
        }
        else if (grade >= 75.0 && grade < 85.0)
        {
            sum_grade = 'B';
        }
        else if (grade >= 65.0 && grade < 75.0)
        {
            sum_grade = 'C';
        }
        else if (grade >= 60.0 && grade < 65.0)
        {
            sum_grade = 'D';
        }
        else
        {
            sum_grade = 'F';
        }
    }

    void show() const
    {
        std::cout << Person::getname() << " " << Person::get_age() << " " << sum_grade << '\n';
    }
};

int main()
{
    int t;
    std::cin >> t;
    while (t--)
    {
        char type;
        std::string name;
        int age;
        std::cin >> type;
        int test_score;

        switch (type)
        {
        case 'R':
        {
            int regular_grade;
            std::cin >> name >> age >> regular_grade >> test_score;
            no_hearing_free n1(regular_grade, test_score, age, name);
            n1.show();
            break;
        }
        case 'S':
        {
            std::cin >> name >> age >> test_score;
            hear_free n1(test_score, age, name);
            n1.show();
            break;
        }
        default:
            break;
        }
    }
    return 0;
}

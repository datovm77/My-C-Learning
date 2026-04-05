#include <iostream>
#include <string>
#include <vector>
class students
{
public:
    std::string name;
    std::string stu_id;
    std::string sex;
    std::string major;
    std::string phone_num;
};

void test01()
{
    int n;
    std::cin >> n;
    std::vector<students> vec(3);
    for (int i = 0; i < n; ++i)
    {
        std::cin >> vec[i].name >> vec[i].stu_id >> vec[i].sex >> vec[i].major >> vec[i].phone_num;
    }

    for (int i = 0; i < n; ++i)
    {
        std::cout << vec[i].name << std::endl;
    }
}

int main()
{
    test01();

    return 0;
}
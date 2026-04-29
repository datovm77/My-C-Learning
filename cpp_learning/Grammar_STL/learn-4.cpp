// 练习string的拼接与append方法，知识点：+=运算符、append截取子串
#include <iostream>
#include <format>
#include <string>

void test01()
{
    std::string str1 = "I";
    str1 += " love"; // I love

    std::string str2 = "GEM LOVE GEM";

    str1.append(str2, 8, 4);
    std::cout << str1 << std::endl;
}

int main()
{
    test01();

    return 0;
}

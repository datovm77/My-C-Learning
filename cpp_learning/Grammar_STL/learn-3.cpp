// 练习std::string的构造与C风格字符串初始化，知识点：string构造、const char*
#include<iostream>
#include<string>

void test01()
{
    std::string s1;

    const char *str = "get everbody moving";
    std::cout << str << std::endl;

    std::string s2 = "gem";
    std::cout << s2 << std::endl;
}


int main()
{
    test01();

    return 0;
}


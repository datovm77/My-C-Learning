// 练习LeetCode 58 最后一个单词长度（简易版），知识点：cin逐词读取
#include <iostream>
#include <string>
//简易版一 - 58. 最后一个单词的长度

void test01()
{
    std::string word;
    std::string lastword;
    while(std::cin >> word)
    {
        lastword = word;
    }
    std::cout << lastword.size() <<std::endl;

}

int main()
{
    test01();

    return 0;
}

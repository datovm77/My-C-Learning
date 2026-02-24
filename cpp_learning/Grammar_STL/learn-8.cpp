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
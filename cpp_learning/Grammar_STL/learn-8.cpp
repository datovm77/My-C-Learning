// 练习LeetCode 58 最后一个单词长度（复杂版），知识点：getline、find、substr
#include <iostream>
#include <string>
#include <vector>
//复杂理解版 - 58. 最后一个单词的长度
void test()
{
    std::string str;

    if (!std::getline(std::cin, str)) {
        std::cout << 0 << std::endl;
        return;
    }

    std::vector<std::string> result;
    std::string space = " ";
    size_t begin = 0;
    size_t end = 0;

    while ((end = str.find(space, begin)) != std::string::npos) {
        std::string temp = str.substr(begin, end - begin);
        if (!temp.empty()) {
            result.push_back(temp);
        }
        begin = end + 1;
    }

    std::string last = str.substr(begin);
    if (!last.empty()) {
        result.push_back(last);
    }

    if (result.empty()) {
        std::cout << 0 << std::endl;
        return;
    }

    size_t last_word_len = result.back().size();
    std::cout << last_word_len << std::endl;
}

int main()
{
    test();
    return 0;
}

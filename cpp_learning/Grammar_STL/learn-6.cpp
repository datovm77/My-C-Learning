// 练习手动实现字符串分割函数，知识点：find、substr、delimiter分隔
#include <vector>
#include<iostream>
#include<string>

void test20() {
    std::string data = "apple,banana,cherry,date";
    std::string delimiter = ",";
    std::vector<std::string> tokens;

    size_t begin = 0;
    size_t end = 0;

    while((end = data.find(delimiter,begin)) != std::string::npos)
    {
        std::string temp_str = data.substr(begin,end-begin);
        tokens.push_back(temp_str);
        begin = end + delimiter.size();
    }

    tokens.push_back(data.substr(begin));

    for(const std::string &val:tokens)
    {
        std::cout << val << std::endl;
    }
}

int main()
{
    test20();

    return 0;
}

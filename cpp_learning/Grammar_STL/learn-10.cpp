#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <limits>
// P1308 [NOIP 2011 普及组] 统计单词数 最复杂

void test01()
{
    std::string word;
    std::string sentence;
    std::cin >> word;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, sentence);

    std::transform(word.begin(), word.end(), word.begin(),
               [](unsigned char c){ return std::tolower(c); });

    std::transform(sentence.begin(), sentence.end(), sentence.begin(),
               [](unsigned char c){ return std::tolower(c); });

    std::string temp = "";
    std::size_t begin = 0;
    std::size_t begin_first = 0;
    std::size_t sum = sentence.size();
    int count = 0;
    int flag = 0;
    while (sum--)
    {
        if (sentence[begin] != ' ')
        {
            temp += sentence[begin];
            if (temp == word && ( begin == sentence.size() - 1 || sentence[begin + 1] == ' '))
            {
                count++;
                if (!flag)
                {
                    flag = 1;
                    begin_first = begin - word.size() + 1;
                }
            }
        }
        else
        {
            temp = "";
        }

        begin++;
    }

    if (count == 0)
        std::cout << -1 << std::endl;
    else
        std::cout << count << " " << begin_first << std::endl;
}

int main()
{
    test01();
    return 0;
}

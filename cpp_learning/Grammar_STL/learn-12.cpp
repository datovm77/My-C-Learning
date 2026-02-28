#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>
#include <limits>
// P1308 [NOIP 2011 普及组] 统计单词数 最简便

void test01()
{
    std::string word;
    std::string text;

    std::cin >> word;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, text);

    std::transform(word.begin(), word.end(), word.begin(), [](unsigned char c)
                   { return std::tolower(c); });

    std::transform(text.begin(), text.end(), text.begin(), [](unsigned char c)
                   { return std::tolower(c); });

    std::string s = " " + text + " ";
    std::string p = " " + word + " ";

    int count = 0;
    int first_pos = -1;

    std::size_t pos = s.find(p);
    while (pos != std::string::npos)
    {
        ++count;
        if (first_pos == -1)
        {
            first_pos = (int)pos;
        }
        pos = s.find(p, pos + 1);
    }

    if(count==0)
    {
        std::cout<<-1<<'\n';
    }
    else{
        std::cout<<count<<' '<<first_pos<<'\n';
    }

}

int main()
{
    test01();


    return 0;
}
#include <iostream>
#include <string>
#include <algorithm>
#include <limits>
// P1308 [NOIP 2011 普及组] 统计单词数 最复杂

void test01()
{
    std::string word;
    std::string text;

    std::cin >> word;
    // 重点：重点记忆
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::getline(std::cin, text);

    // 把字符串转化为小写
    std::transform(word.begin(), word.end(), word.begin(), [](unsigned char c)
                   { return std::tolower(c); });
    std::transform(text.begin(), text.end(), text.begin(), [](unsigned char c)
                   { return std::tolower(c); });

    int count = 0;
    int first_pos = -1;
    int n = text.size();

    int i = 0;
    while (i < n)
    {
        while (i < n && text[i] == ' ')
        {
            ++i;
        }
        if (i >= n)
            break;

        int l = i;
        while (i < n && text[i] != ' ')
        {
            ++i;
        }
        int r = i; //[l,r)

        if ((r - l) == word.size() && text.compare(l, r - l, word) == 0)
        {
            ++count;
            if (first_pos == -1)
                first_pos = l;
        }
    }

    if (count == 0)
    {
        std::cout << -1 << '\n';
    }
    else
    {
        std::cout << count << ' ' << first_pos << '\n';
    }
}

int main()
{
    test01();

    return 0;
}
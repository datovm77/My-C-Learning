#include <iostream>
// P1055 [NOIP 2008 普及组] ISBN 号码
void test01()
{
    std::string isbn;
    std::cin >> isbn;

    std::string s1 = "";
    for (char c : isbn)
    {
        if (c != '-')
            s1 += c;
    }
    int sum = 0;
    for (int i = 0; i < 9; ++i)
    {
        sum += (s1[i] - '0') * (i + 1);
    }

    int result = sum % 11;
    char check = (result == 10) ? 'X' : ('0' + result);

    if(s1[9]==check)
    {
        std::cout << "Right" << std::endl;
    }
    else{
        isbn.back() = check;
        std::cout<<isbn<<std::endl;
    }
}

int main()
{
    test01();
    return 0;
}
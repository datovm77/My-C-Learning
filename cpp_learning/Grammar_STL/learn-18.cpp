// 练习NOIP P1055 ISBN号码校验（C风格），知识点：scanf格式化输入、取模校验
#include <cstdio>
#include <iostream>

// P1055 [NOIP 2008 普及组] ISBN 号码 C语言风格版
int main()
{
    int s1, s2, s3;
    char sign;
    scanf("%d-%d-%d-%c", &s1, &s2, &s3, &sign);

    int digit[10] = {0}; // digit[1..9]
    digit[1] = s1 % 10;

    for (int i = 4; i >= 2; --i)
    {
        digit[i] = s2 % 10;
        s2 /= 10;
    }

    for (int i = 9; i >= 5; --i)
    {
        digit[i] = s3 % 10;
        s3 /= 10;
    }

    int sum = 0;
    for (int i = 1; i <= 9; ++i)
    {
        sum += digit[i] * i;
    }

    int result = sum % 11;
    char check = (result == 10) ? 'X' : char('0' + result);

    if (check == sign)
    {
        std::cout << "Right\n";
    }
    else
    {
        std::cout << digit[1] << '-'
                  << digit[2] << digit[3] << digit[4] << '-'
                  << digit[5] << digit[6] << digit[7] << digit[8] << digit[9] << '-'
                  << check << '\n';
    }

    return 0;
}

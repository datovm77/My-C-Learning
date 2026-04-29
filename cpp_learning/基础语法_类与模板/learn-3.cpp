// 练习C风格字符数组与std::string的基本使用对比
#include<iostream>

void Log(const char* message)
{
    std::cout << message << std::endl;
}

int Multiply(int a,int b)
{
    Log("Multiply");
    return a*b;
}


int main()
{

    std::cout << Multiply(5,8) << std::endl;
}
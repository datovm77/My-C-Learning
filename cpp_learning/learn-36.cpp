#include<iostream>
#include<format>
#include<string>
//函数调用重载
class MyPrint
{
public:
    void operator()(std::string test)
    {
        std::cout << test <<std::endl;
    }

};

class MyAdd
{
public:
    int operator()(int num1,int num2)
    {
        return num1+num2;
    }


};

void test01()
{
    MyPrint m1;
    m1("get everbody moving");
}

void test02()
{
    MyAdd m1;
    int result = m1(100,102);
    std::cout << result <<std::endl;

    //匿名函数对象
    std::cout << MyAdd()(100,102) << std::endl;
}

int main()
{
    test01();
    test02();
}
#include<iostream>
#include<format>
#include<string>
//代码区  ： 共享+只读，用于存放二进制代码
//全局区  ： 存放全局变量和静态变量以及常量 ：数据在程序结束后由操作系统释放
//栈区    ： 
//堆区

//全局
int a = 10;  //全局变量，全程序可见
static int b = 11;//静态变量，本程序可见，可以修改
const int c = 15;  //const修饰的全局变量  --全局常量
std::string d = "lovegem"; //字符串常量


int main()
{
    const int e = 15;  //const修饰的局部变量--不在全局区0...

    std::cout << std::format("全局变量a的值是{}",a) << std::endl;
    std::cout << std::format("静态a的值是{}",b) << std::endl;
    std::cout << std::format("变量a的值是{}",c) << std::endl;


    return 0; 
}
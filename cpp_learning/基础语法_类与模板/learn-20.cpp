#include<iostream>
#include<format>
//类与对象
//三大特性:封装，继承，多态
//封装：把属性与行为作为一个整体
const double PI = 3.1415926;
class Circle
{
    //访问权限
    //公共权限
public:
    //属性
    //半径
    int m_r;

    //行为
    //获取圆的周长
    double calculateZC()
    {
        return 2*PI*m_r;
    }

};

int main()
{
    Circle c1;//圆的对象,实例化
    c1.m_r = 10;
    std::cout << std::format("圆的周长为：{}",c1.calculateZC()) << std::endl;
    
    return 0;
}
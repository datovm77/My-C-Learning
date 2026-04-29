// 练习友元类的声明与使用
#include<iostream>
#include<string>
using namespace std;
class Building;
class goodGay
{
public:

    goodGay();
    void visit();

private:
    Building *building;
};

class Building
{
    //告诉编译器 goodGay类是Building类的好朋友，可以访问到Building类中私有内容
    friend class goodGay;
public:
    string m_SittingRoom; //客厅
private:
    string m_Bedroom;     //卧室（由于图片截断，根据代码逻辑补全）

public:
    Building():m_SittingRoom("客厅"),m_Bedroom("卧室") {}

};

// Building::Building()
// {
//     this->m_SittingRoom = "客厅";
//     this->m_Bedroom = "卧室";
// }

goodGay::goodGay()
{
    building = new Building;
}

void goodGay::visit()
{
    cout << "好基友正在访问"<<building->m_SittingRoom<<endl;
    cout << "好基友正在访问"<<building->m_Bedroom<<endl;
}

void test01()
{
    goodGay gg;
    gg.visit();
}

int main()
{
    test01();

    return 0;
}

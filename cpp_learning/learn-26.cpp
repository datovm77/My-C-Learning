#include<iostream>
#include<format>
class BankAccount {
public:
    static int accountCount;  // 静态成员变量
    int balance;              // 普通成员变量
    
    BankAccount() {
        accountCount++;  // 每创建一个对象就加1
    }
};

int BankAccount::accountCount = 0;

void test01()
{
    BankAccount acc1;
    BankAccount acc2;
    BankAccount acc3;
    std::cout << std::format("获取方式一：{}",BankAccount::accountCount) << std::endl;
    std::cout << std::format("获取方式二：{}",acc2.accountCount) << std::endl;
    std::cout << std::format("获取方式三：{}",acc1.accountCount) << std::endl;

}


int main()
{
    test01();

    return 0;
}














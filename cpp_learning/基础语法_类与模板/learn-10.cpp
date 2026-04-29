// 练习std::string拼接、format格式化与ends_with查询操作
#include<iostream>
// #include<string.h> //老！
#include<string>
#include<format>
int main()
{
    std::string name3 = "lovegem";
    const char *name1 = "love_everbody";
       
    
    std::cout<< name3.size() << std::endl;
    // std::cout<< strlen(name1) << std::endl;//老！
    std::cout<< name3.size() << std::endl;
    std::cout<< name3.size() << std::endl;
    return 0;
}
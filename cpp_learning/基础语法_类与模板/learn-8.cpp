// 练习C风格字符串与std::string，知识点：字符数组、字符串字面量与size
#include<iostream>
int main()
{
    const char* name = "get everbody moving";
    char name2[4] = {'g','e','m','\0'};
    std::string name3 = "lovegem";
    std::cout<< name << std::endl;
    std::cout<< name2 << std::endl;
    std::cout<< name3 << std::endl;
       
    
    std::cout<< name3.size() << std::endl;
    return 0;
}

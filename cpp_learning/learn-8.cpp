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
#include <iostream>
#include <string>
class robot
{
private:
    int level = 0;
    std::string name = "";
    char type;

public:
    robot(const std::string &name, const char &type, const int &level)
    {
        this->name = name;
        this->type = type;
        this->level = level;
    }
    std::string getname() const
    {
        return name;
    }
    int getlevel() const
    {
        return level;
    }
    friend bool robot_now(robot &r1, const char &type);
};

bool robot_now(robot &r1, const char &type)
{
    if (r1.type != type)
    {
        r1.type = type;
        return true;
    }
    else
    {
        return false;
    }
}

void print_my(const robot &r1, const char &type)
{
    std::string name = r1.getname();
    int level = r1.getlevel();
    switch (type)
    {
    case 'N':
        std::cout << name << "--" << type << "--" << level << "--" << level * 5 << "--" << level * 5 << "--" << level * 5 << '\n';
        break;
    case 'A':
        std::cout << name << "--" << type << "--" << level << "--" << level * 5 << "--" << level * 10 << "--" << level * 5 << '\n';
        break;
    case 'D':
        std::cout << name << "--" << type << "--" << level << "--" << level * 5 << "--" << level * 5 << "--" << level * 10 << '\n';
        break;
    case 'H':
        std::cout << name << "--" << type << "--" << level << "--" << level * 50 << "--" << level * 5 << "--" << level * 5 << '\n';
        break;

    default:
        break;
    }
}

int main()
{
    int t;
    std::cin >> t;
    int succs = 0;
    while (t--)
    {
        std::string name;
        char type;
        char tran_type;
        int level;
        std::cin >> name >> type >> level;
        std::cin >> tran_type;
        robot r1(name, type, level);
        if (robot_now(r1, tran_type))
        {
            succs++;
            print_my(r1, tran_type);
        }
        else
        {
            print_my(r1, tran_type);
        }
        
    }
    std::cout<<"The number of robot transform is "<<succs<<'\n';

    return 0;
}
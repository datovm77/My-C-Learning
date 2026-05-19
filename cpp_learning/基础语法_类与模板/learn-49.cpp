#include <iostream>

class Animal
{
public:
    virtual void speak() { std::cout << "动物在叫" << std::endl; }
    virtual void eat() { std::cout << "动物在吃" << std::endl; }
};

class Cat : public Animal
{
public:
    void speak() { std::cout << "喵喵喵" << std::endl; } // 重写
    // eat()未重写，使用父类的
};

int main()
{
    Animal *animal = new Cat();
    animal->speak();
    return 0;
}
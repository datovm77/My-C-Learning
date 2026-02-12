#include <iostream>
#include <string>
using namespace std;

// ============================================================
//                    C++ 多态详解
// ============================================================
// 多态：同一操作作用于不同对象，产生不同的行为
// 核心机制：虚函数 (virtual)
// ============================================================

// ===== 1. 基类：使用虚函数 =====
class Shape
{
protected:
    string name;

public:
    Shape(string n) : name(n) {}

    // 🔑 virtual 关键字使这个函数成为虚函数
    // 虚函数允许子类重写，并通过父类指针调用子类版本
    virtual void draw()
    {
        cout << "绘制一个形状: " << name << endl;
    }

    virtual double area()
    {
        return 0;
    }

    // 虚析构函数（重要！后面会解释）
    virtual ~Shape()
    {
        cout << "Shape 析构函数" << endl;
    }
};

// ===== 2. 派生类：重写虚函数 =====
class Circle : public Shape
{
private:
    double radius;

public:
    Circle(double r) : Shape("圆形"), radius(r) {}

    // override 关键字（C++11）：确保正确重写父类虚函数
    // 如果父类没有这个虚函数，编译器会报错
    void draw() override
    {
        cout << "绘制圆形 ○，半径: " << radius << endl;
    }

    double area() override
    {
        return 3.14159 * radius * radius;
    }

    ~Circle()
    {
        cout << "Circle 析构函数" << endl;
    }
};

class Rectangle : public Shape
{
private:
    double width, height;

public:
    Rectangle(double w, double h) : Shape("矩形"), width(w), height(h) {}

    void draw() override
    {
        cout << "绘制矩形 □，宽: " << width << ", 高: " << height << endl;
    }

    double area() override
    {
        return width * height;
    }

    ~Rectangle()
    {
        cout << "Rectangle 析构函数" << endl;
    }
};

class Triangle : public Shape
{
private:
    double base, height;

public:
    Triangle(double b, double h) : Shape("三角形"), base(b), height(h) {}

    void draw() override
    {
        cout << "绘制三角形 △，底: " << base << ", 高: " << height << endl;
    }

    double area() override
    {
        return 0.5 * base * height;
    }

    ~Triangle()
    {
        cout << "Triangle 析构函数" << endl;
    }
};

// ===== 3. 多态的实际应用 =====
// 使用父类指针数组管理不同类型的子类对象
void demonstratePolymorphism()
{
    cout << "\n========== 多态演示 ==========\n"
         << endl;

    // 父类指针指向不同的子类对象
    Shape *shapes[3];
    shapes[0] = new Circle(5.0);
    shapes[1] = new Rectangle(4.0, 6.0);
    shapes[2] = new Triangle(3.0, 4.0);

    // 统一调用，但执行不同的行为（多态！）
    for (int i = 0; i < 3; i++)
    {
        shapes[i]->draw(); // 根据实际对象类型调用对应版本
        cout << "面积: " << shapes[i]->area() << endl;
        cout << "---" << endl;
    }

    // 释放内存（虚析构函数确保正确释放）
    for (int i = 0; i < 3; i++)
    {
        delete shapes[i];
    }
}

// ===== 4. 纯虚函数和抽象类 =====
// 抽象类：包含至少一个纯虚函数的类，不能实例化
class Animal
{
protected:
    string name;

public:
    Animal(string n) : name(n) {}

    // 纯虚函数：= 0 表示没有实现，子类必须重写
    virtual void speak() = 0;
    virtual void move() = 0;

    // 普通虚函数
    virtual void info()
    {
        cout << "我是一只" << name << endl;
    }

    virtual ~Animal() {}
};

class Dog : public Animal
{
public:
    Dog() : Animal("狗") {}

    void speak() override
    {
        cout << name << ": 汪汪汪！" << endl;
    }

    void move() override
    {
        cout << name << " 在奔跑" << endl;
    }
};

class Cat : public Animal
{
public:
    Cat() : Animal("猫") {}

    void speak() override
    {
        cout << name << ": 喵喵喵~" << endl;
    }

    void move() override
    {
        cout << name << " 在跳跃" << endl;
    }
};

class Bird : public Animal
{
public:
    Bird() : Animal("鸟") {}

    void speak() override
    {
        cout << name << ": 叽叽喳喳~" << endl;
    }

    void move() override
    {
        cout << name << " 在飞翔" << endl;
    }
};

void demonstrateAbstractClass()
{
    cout << "\n========== 抽象类演示 ==========\n"
         << endl;

    // Animal a;  // ❌ 错误！抽象类不能实例化

    Animal *animals[3];
    animals[0] = new Dog();
    animals[1] = new Cat();
    animals[2] = new Bird();

    for (int i = 0; i < 3; i++)
    {
        animals[i]->info();
        animals[i]->speak();
        animals[i]->move();
        cout << "---" << endl;
        delete animals[i];
    }
}

// ===== 5. 虚析构函数的重要性 =====
class Base
{
public:
    Base() { cout << "Base 构造函数" << endl; }

    // ❌ 非虚析构函数
    // ~Base() { cout << "Base 析构函数" << endl; }

    // ✅ 虚析构函数
    virtual ~Base() { cout << "Base 析构函数" << endl; }
};

class Derived : public Base
{
private:
    int *data;

public:
    Derived()
    {
        data = new int[100];
        cout << "Derived 构造函数，分配了内存" << endl;
    }

    ~Derived()
    {
        delete[] data;
        cout << "Derived 析构函数，释放了内存" << endl;
    }
};

void demonstrateVirtualDestructor()
{
    cout << "\n========== 虚析构函数演示 ==========\n"
         << endl;

    Base *ptr = new Derived();
    delete ptr; // 如果没有虚析构函数，只会调用 Base 的析构函数！
                // 导致 Derived 的内存泄漏

    cout << "\n如果没有 virtual ~Base()，Derived 的析构函数不会被调用！" << endl;
    cout << "这会导致内存泄漏！" << endl;
}

// ===== 6. 多态的底层原理：虚函数表 =====
class Example
{
public:
    virtual void func1() { cout << "func1" << endl; }
    virtual void func2() { cout << "func2" << endl; }
    void normalFunc() { cout << "普通函数" << endl; }
};

void explainVTable()
{
    cout << "\n========== 虚函数表原理 ==========\n"
         << endl;

    cout << R"(
    每个含有虚函数的类都有一个虚函数表(vtable)
    每个对象都有一个指向虚函数表的指针(vptr)
    
    ┌─────────────────────────────────────────────────────┐
    │  Example 对象                                        │
    │  ┌─────────┐                                        │
    │  │  vptr ──┼──→ ┌─────────────────────────────┐    │
    │  └─────────┘    │ 虚函数表 (vtable)            │    │
    │                 │ ┌─────────────────────────┐ │    │
    │                 │ │ &Example::func1()       │ │    │
    │                 │ ├─────────────────────────┤ │    │
    │                 │ │ &Example::func2()       │ │    │
    │                 │ └─────────────────────────┘ │    │
    │                 └─────────────────────────────┘    │
    └─────────────────────────────────────────────────────┘
    
    当调用虚函数时：
    1. 通过 vptr 找到 vtable
    2. 从 vtable 中找到对应的函数地址
    3. 调用正确的函数版本
    
    这就是为什么虚函数调用比普通函数稍慢的原因。
    )" << endl;
}

// ===== 7. override 和 final 关键字 =====
class Base2
{
public:
    virtual void func() { cout << "Base2::func" << endl; }
    virtual void doSomething() { cout << "Base2::doSomething" << endl; }
};

class Derived2 : public Base2
{
public:
    // override: 确保正确重写（拼写错误会报错）
    void func() override { cout << "Derived2::func" << endl; }

    // final: 禁止进一步重写
    void doSomething() override final
    {
        cout << "Derived2::doSomething (final)" << endl;
    }
};

// class Derived3 : public Derived2 {
// public:
//     void doSomething() override { }  // ❌ 错误！final 不能被重写
// };

// ===== main 函数 =====
int main()
{
    cout << "╔════════════════════════════════════════════╗" << endl;
    cout << "║          C++ 多态完整教程                   ║" << endl;
    cout << "╚════════════════════════════════════════════╝" << endl;

    // 1. 基本多态演示
    demonstratePolymorphism();

    // 2. 抽象类演示
    demonstrateAbstractClass();

    // 3. 虚析构函数演示
    demonstrateVirtualDestructor();

    // 4. 虚函数表原理
    explainVTable();

    cout << "\n========== 总结 ==========\n"
         << endl;
    cout << R"(
    ╔═══════════════════════════════════════════════════════════╗
    ║                    多态核心要点                            ║
    ╠═══════════════════════════════════════════════════════════╣
    ║ 1. virtual 关键字：声明虚函数                              ║
    ║ 2. override 关键字：确保正确重写（C++11）                  ║
    ║ 3. = 0：纯虚函数，使类成为抽象类                           ║
    ║ 4. virtual 析构函数：确保正确释放子类资源                  ║
    ║ 5. final 关键字：禁止重写或继承                            ║
    ╠═══════════════════════════════════════════════════════════╣
    ║                    多态三条件                              ║
    ╠═══════════════════════════════════════════════════════════╣
    ║ ① 有继承关系                                              ║
    ║ ② 子类重写父类虚函数                                      ║
    ║ ③ 父类指针/引用指向子类对象                               ║
    ╚═══════════════════════════════════════════════════════════╝
    )" << endl;

    return 0;
}

/*
预期输出：
╔════════════════════════════════════════════╗
║          C++ 多态完整教程                   ║
╚════════════════════════════════════════════╝

========== 多态演示 ==========

绘制圆形 ○，半径: 5
面积: 78.5397
---
绘制矩形 □，宽: 4, 高: 6
面积: 24
---
绘制三角形 △，底: 3, 高: 4
面积: 6
---
Circle 析构函数
Shape 析构函数
Rectangle 析构函数
Shape 析构函数
Triangle 析构函数
Shape 析构函数

========== 抽象类演示 ==========

我是一只狗
狗: 汪汪汪！
狗 在奔跑
---
我是一只猫
猫: 喵喵喵~
猫 在跳跃
---
我是一只鸟
鸟: 叹叽喳喳~
鸟 在飞翔
---

========== 虚析构函数演示 ==========

Base 构造函数
Derived 构造函数，分配了内存
Derived 析构函数，释放了内存
Base 析构函数

如果没有 virtual ~Base()，Derived 的析构函数不会被调用！
这会导致内存泄漏！

========== 虚函数表原理 ==========
...（原理图解）

========== 总结 ==========
...（要点总结）
*/

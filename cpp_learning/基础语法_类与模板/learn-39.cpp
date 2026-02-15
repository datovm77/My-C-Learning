#include <iostream>
#include <string>
using namespace std;

// ===== 情况1：基类没有默认构造函数 =====
class Animal {
protected:
    string name;
    int age;
public:
    // 只有带参数的构造函数，没有默认构造函数
    Animal(string n, int a) {
        name = n;
        age = a;
        cout << "Animal 构造函数被调用: " << name << endl;
    }
    
    void showInfo() {
        cout << "名字: " << name << ", 年龄: " << age << endl;
    }
};

// 派生类 Dog
class Dog : public Animal {
private:
    string breed;  // 品种
public:
    // ❌ 错误写法：不显式调用基类构造函数
    // Dog(string n, int a, string b) {
    //     breed = b;  // 编译错误！Animal 没有默认构造函数
    // }
    
    // ✅ 正确写法：使用初始化列表显式调用基类构造函数
    Dog(string n, int a, string b) : Animal(n, a) {  // 显式调用 Animal(n, a)
        breed = b;
        cout << "Dog 构造函数被调用: " << breed << endl;
    }
    
    void bark() {
        cout << name << " 汪汪叫!" << endl;
    }
};

// ===== 情况2：基类有默认构造函数 =====
class Vehicle {
protected:
    int wheels;
public:
    Vehicle() {  // 默认构造函数
        wheels = 4;
        cout << "Vehicle 默认构造函数" << endl;
    }
    
    Vehicle(int w) {  // 带参构造函数
        wheels = w;
        cout << "Vehicle 带参构造函数" << endl;
    }
};

class Car : public Vehicle {
private:
    string brand;
public:
    // 基类有默认构造函数时，可以不显式调用
    Car(string b) {  // 会自动调用 Vehicle()
        brand = b;
        cout << "Car 构造函数" << endl;
    }
};

int main() {
    cout << "===== 创建 Dog 对象 =====" << endl;
    Dog dog("旺财", 3, "金毛");
    dog.showInfo();
    dog.bark();
    
    cout << "\n===== 创建 Car 对象 =====" << endl;
    Car car("宝马");
    
    return 0;
}

/*
输出结果：
===== 创建 Dog 对象 =====
Animal 构造函数被调用: 旺财
Dog 构造函数被调用: 金毛
名字: 旺财, 年龄: 3
旺财 汪汪叫!

===== 创建 Car 对象 =====
Vehicle 默认构造函数
Car 构造函数

总结：
1. 基类没有默认构造函数 → 派生类必须用初始化列表显式调用基类构造函数
2. 基类有默认构造函数 → 派生类可以不显式调用（会自动调用默认的）
3. 语法格式：派生类构造函数(参数) : 基类构造函数(参数) { }
*/

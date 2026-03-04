# C++ 迭代器失效详解

迭代器失效的本质是：**vector 在内存中是连续存储的**，一旦触发扩容或元素移动，原来的指针/迭代器就指向了"已释放或已移动"的内存，继续使用就是未定义行为（UB）。

------

## 基础概念：为什么会失效？

```cpp
// vector 内部大概长这样：
// [ 1 | 2 | 3 | _ | _ ]
//   ↑                 ↑
// begin()           end()  (指向最后一个元素的下一位)
//
// 扩容时，vector 申请一块"更大的新内存"，把数据复制过去，
// 释放旧内存 —— 所有指向旧内存的迭代器全部失效！
```

------

## 1. `push_back` / `emplace_back`

**规则：触发扩容 → 全部失效；未扩容 → 仅 `end()` 失效**

```cpp
#include <vector>
#include <iostream>

int main() {
    std::vector<int> v = {1, 2, 3};
    v.reserve(10); // 先预留空间，确保不扩容

    auto it = v.begin(); // 指向 1
    v.push_back(4);      // 未扩容，it 仍然有效

    std::cout << *it << "\n"; // ✅ 输出 1，安全

    // ————————————————————————————————
    // 危险情况：未 reserve，触发扩容
    std::vector<int> v2 = {1, 2, 3}; // size==capacity==3（通常）
    auto it2 = v2.begin();
    v2.push_back(4); // 触发扩容！旧内存被释放

    // std::cout << *it2; // ❌ UB！it2 已失效
}
```

**实际陷阱：在循环中边遍历边 push_back**

```cpp
std::vector<int> v = {1, 2, 3};
for (auto it = v.begin(); it != v.end(); ++it) {
    v.push_back(*it * 2); // ❌ 极其危险！push_back 可能扩容，
                          //    导致 it 和 v.end() 全部失效
                          //    → 死循环 + UB
}
```

------

## 2. `insert` / `emplace`

**规则：触发扩容 → 全部失效；未扩容 → 插入点及之后失效**

```cpp
std::vector<int> v = {1, 2, 3, 4, 5};
v.reserve(10); // 不扩容

auto it = v.begin() + 3; // 指向元素 4
std::cout << *it << "\n"; // 4

v.insert(v.begin() + 1, 99); // 在 2 前面插入 99
// 内存移动：[1, 99, 2, 3, 4, 5]
//           插入点(1)之后的元素全部往后挪了一位

// std::cout << *it; // ❌ it 原来指向索引3(元素4)，
                     //    现在索引3是元素3，语义已经错了
                     //    （内存没释放但指向位置的含义变了）
```

**正确做法：用 insert 的返回值**

```cpp
std::vector<int> v = {1, 2, 3, 4, 5};
v.reserve(10);

auto it = v.insert(v.begin() + 1, 99); // insert 返回指向新插入元素的迭代器
// 继续用 it 操作插入后的元素 ✅
std::cout << *it << "\n"; // 99
```

------

## 3. `erase`

**规则：删除点及之后的迭代器全部失效（删除点之前的安全）**

```cpp
std::vector<int> v = {1, 2, 3, 4, 5};

auto it_before = v.begin();     // 指向 1
auto it_target = v.begin() + 2; // 指向 3（要删除它）
auto it_after  = v.begin() + 3; // 指向 4

v.erase(it_target); // 删除 3，后面的元素向前移动

std::cout << *it_before << "\n"; // ✅ 1，删除点之前安全
// std::cout << *it_after;       // ❌ UB！删除点之后已失效
```

**经典陷阱：循环中用 erase 删除元素**

```cpp
// ❌ 错误写法：跳过元素！
std::vector<int> v = {1, 2, 3, 4, 5};
for (auto it = v.begin(); it != v.end(); ++it) {
    if (*it % 2 == 0) {
        v.erase(it); // erase 后 it 失效，再 ++it 就跳过了下一个元素
    }
}

// ✅ 正确写法：erase 返回下一个有效迭代器
for (auto it = v.begin(); it != v.end(); ) {
    if (*it % 2 == 0) {
        it = v.erase(it); // 用返回值更新 it，不要 ++it
    } else {
        ++it;
    }
}
```

------

## 4. `resize`

**规则：扩大且触发扩容 → 全部失效；缩小 → 删除点之后失效**

```cpp
std::vector<int> v = {1, 2, 3, 4, 5};
auto it = v.begin() + 2; // 指向 3

// 情况A：缩小（不扩容）
v.resize(3); // v = {1, 2, 3}，it 指向的 3 还在 ✅（但 begin()+3 以后失效）

// 情况B：扩大但不超过 capacity（不扩容）
v.reserve(20);
auto it2 = v.begin();
v.resize(10); // 补零，it2 仍有效 ✅

// 情况C：扩大且超过 capacity（触发扩容）
std::vector<int> v2 = {1, 2, 3}; // capacity 刚好是 3
auto it3 = v2.begin();
v2.resize(100); // 触发扩容！
// std::cout << *it3; // ❌ UB！
```

------

## 5. `reserve`

**规则：capacity 改变 → 全部失效；capacity 未改变（传入值 ≤ 当前 capacity）→ 不失效**

```cpp
std::vector<int> v = {1, 2, 3};
auto it = v.begin();

v.reserve(2); // 2 <= capacity，什么都不做
std::cout << *it << "\n"; // ✅ 安全

v.reserve(100); // 触发重新分配！
// std::cout << *it; // ❌ UB！it 指向旧内存
```

**`reserve` 的正确用法：在获取迭代器之前调用**

```cpp
std::vector<int> v;
v.reserve(100);      // 先 reserve
auto it = v.begin(); // 再获取迭代器
v.push_back(1);      // 不超过 capacity，it 安全 ✅
```

------

## 6. `clear`

**规则：全部失效**

```cpp
std::vector<int> v = {1, 2, 3};
auto it = v.begin();

v.clear(); // 所有元素销毁（但 capacity 通常不变）

// std::cout << *it; // ❌ UB！元素已销毁，it 失效
// 注意：v.begin() == v.end() 此时成立，但不能解引用
```

------

## 7. `swap`

**规则：迭代器本身不失效，但它们现在指向的是"另一个容器"的元素**

```cpp
std::vector<int> a = {1, 2, 3};
std::vector<int> b = {4, 5, 6};

auto it_a = a.begin(); // 指向 a 的第一个元素 (1)
auto it_b = b.begin(); // 指向 b 的第一个元素 (4)

a.swap(b);
// a 现在是 {4, 5, 6}，b 现在是 {1, 2, 3}

// 迭代器"跟着数据走"！
std::cout << *it_a << "\n"; // ✅ 输出 1（it_a 现在属于 b）
std::cout << *it_b << "\n"; // ✅ 输出 4（it_b 现在属于 a）

// 常见坑：
for (auto it = a.begin(); it != a.end(); ++it) { // end() 也跟着走了 ✅
    std::cout << *it; // 4 5 6
}
```

------

## 总结速查表

| 操作                         | 触发条件       | 失效范围           |
| ---------------------------- | -------------- | ------------------ |
| `push_back` / `emplace_back` | 触发扩容       | 全部               |
|                              | 未扩容         | 仅 `end()`         |
| `insert` / `emplace`         | 触发扩容       | 全部               |
|                              | 未扩容         | 插入点及之后       |
| `erase`                      | 始终           | 删除点及之后       |
| `resize`                     | 扩大且触发扩容 | 全部               |
|                              | 缩小           | 删除点之后         |
| `reserve`                    | capacity 改变  | 全部               |
| `clear`                      | 始终           | 全部               |
| `swap`                       | 始终           | 不失效，但换容器了 |

**黄金法则：凡是可能修改 vector 结构的操作，之后不要复用旧迭代器，用操作的返回值重新获取。**
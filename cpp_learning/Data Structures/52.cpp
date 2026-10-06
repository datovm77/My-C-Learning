#include <iostream>
#define ok 0
#define error -1

// 顺序表类定义
class SeqList
{
private:
    int *list;   // 元素数组
    int maxsize; // 顺序表最大长度
    int size;    // 顺序表实际长度
public:
    SeqList();                        // 构造函数
    ~SeqList();                       // 析构函数
    int list_size();                  // 获取顺序表实际长度
    int list_insert(int i, int item); // 插入一个元素，参数是插入的数值和位置
    int list_del(int i);              // 删除一个元素，参数是删除的位置
    int list_get(int i);              // 获取一个元素，参数是获取的位置
    void list_display();              // 输出整个顺序表
};

SeqList::SeqList()
{
    maxsize = 1000;
    size = 0;
    list = new int[maxsize];
}
SeqList::~SeqList()
{
    delete[] list;
}

int SeqList::list_size()
{
    return size;
}

// 从[size-1]到[i-1]都需要往后移动一格
int SeqList::list_insert(int i, int item)
{
    // [原错误写法保留] if (i <= 0 || i > size + 2) return -1;
    // [说明] 1-indexed 的合法插入位置是 1 ~ size+1，多允许了一个 size+2。
    //        例 size=0 时 insert(2,x) 本应失败却会成功，导致空洞。
    if (i < 1 || i > size + 1)
        return error; // 原来写 return -1; 功能一样，但用宏 error 更符合题给定义
    // [新增遗漏检查] 原写法缺满表判断，size==maxsize 时会堆越界写
    if (size >= maxsize)
        return error;

    // [原错误顺序保留] int t = size - 1; size++; while (t >= i - 1) ...
    // [说明] 先 size++ 再搬移虽能跑，但 t 的初值含义变成“新size-2”，易错。
    //        改为先搬移、再 size++，语义更清晰。
    int t = size - 1;
    while (t >= i - 1)
    {
        list[t + 1] = list[t];
        t--;
    }
    list[i - 1] = item;
    size++;
    // [原错误写法保留] return 1;
    // [说明] 题给宏 ok=0, error=-1，成功应返回 ok 而不是 1
    return ok;
}

int SeqList::list_del(int i)
{
    // [原错误写法保留] if (i <= 0 || i > size + 1) return -1;
    // [说明] 合法删除位置是 1 ~ size，多允许了 size+1。
    //        例 size=7 时 del(8) 本应失败却会成功并产生越界读写。
    if (i < 1 || i > size)
        return error;
    int t = i - 1;
    // [原错误写法保留] while (t <= size - 1) { list[t] = list[t + 1]; t++; }
    // [说明] t==size-1 时会读 list[size]（越界一格，虽在 maxsize 堆内不崩，但读到未初始化值）。
    //        应只搬到 size-2 -> size-1 为止。
    while (t < size - 1)
    {
        list[t] = list[t + 1];
        t++;
    }
    size--;
    // [原错误写法保留] return 1; [说明] 同 insert，成功应返回 ok(0)
    return ok;
}

int SeqList::list_get(int i)
{
    // [原错误写法保留] if (i <= 0 || i > size + 1) return -1;
    // [说明] 合法查找位置是 1 ~ size，多允许了 size+1，会读到 size 位置的垃圾值。
    if (i < 1 || i > size)
        return error; // 原来写 return -1; 功能一样，改用宏

    // [注意/设计缺陷说明] 用 -1 既表示“元素值-1”又表示“查找失败”，
    // 若表中存了 -1，main 里 flag==-1 会误判为 error。本题数据为正数可过，
    // 严格做法应改接口（如 bool list_get(i, int &x)），但题给函数签名固定，只能保留并备注。
    return list[i - 1];
}

void SeqList::list_display()
{
    int i = 0;
    std::cout << size << " ";
    while (i < size)
    {
        std::cout << list[i] << " ";
        i++;
    }
    std::cout << '\n';
}

int main()
{
    int n;
    int t = 1;
    std::cin >> n;
    SeqList s1;
    while (t <= n)
    {
        int number;
        std::cin >> number;
        s1.list_insert(t, number);
        t++;
    }
    s1.list_display();

    int site, value;
    std::cin >> site >> value;
    int flag = s1.list_insert(site, value);
    if (flag == -1)
        std::cout << "error" << '\n';
    else
        s1.list_display();

    std::cin >> site >> value;
    int flag2 = s1.list_insert(site, value);
    if (flag2 == -1)
        std::cout << "error" << '\n';
    else
        s1.list_display();

    int remove;
    std::cin >> remove;
    int flag3 = s1.list_del(remove);

    if (flag3 == -1)
        std::cout << "error" << '\n';
    else
        s1.list_display();

    int remove2;
    std::cin >> remove2;
    int flag4 = s1.list_del(remove2);

    if (flag4 == -1)
        std::cout << "error" << '\n';
    else
        s1.list_display();

    int find1;
    std::cin >> find1;
    int flag5 = s1.list_get(find1);

    if (flag5 == -1)
        std::cout << "error" << '\n';
    else
        std::cout << flag5 << '\n';

    int find2;
    std::cin >> find2;
    // [原错误写法保留] int flag6 = s1.list_get(find1);
    // [说明] 复制粘贴错误：第二次查找用了 find1，导致重复查第一次。
    //        样例 find 0 / 5 时第二次应输出 44，却输出 error。
    int flag6 = s1.list_get(find2);

    if (flag6 == -1)
        std::cout << "error" << '\n';
    else
        std::cout << flag6 << '\n';

    return 0;
}
#include <iostream>

class SeqList
{
private:
    int *list;
    int maxsize;
    int size;

public:
    SeqList();
    ~SeqList();
    int multiinsert(int i, int n, int item[]);
    int multidel(int i, int n);
    void list_display();
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

int SeqList::multiinsert(int i, int n, int item[])
{
    if (i < 1 || i > size + 1)
        return -1;

    if (n <= 0)
        return -1;
    if (size + n > maxsize)
        return -1;
    if (item == nullptr)
        return -1;

    int begin_index = i - 1;
    for (int j = size - 1; j >= begin_index; j--)
    {
        list[j + n] = list[j];
    }
    int index = 0;
    for (int j = begin_index; j < begin_index + n; j++)
    {
        list[j] = item[index++];
    }
    size += n;

    return 1;
}

int SeqList::multidel(int i, int n)
{
    // ---- 错误写法1（已修正，保留对比）：缺少对 n 的合法性检查 ----
    // 原写法只有：int rest = size - i - n + 1;
    //             if (rest < 0 || i < 1 || i > size) return -1;
    // 说明：当 n == 0 时会当作成功返回(与 multiinsert 的 n<=0 返回-1 不一致)；
    //       当 n == -1 时，rest = size-i-n+1 反而变大，绕过检查，
    //       之后 size -= n 等价于 size+1，且搬移逻辑错乱，会破坏数据。
    //       实测：size=4 时 multidel(2,-1) 会让 size 变成 5，数据全被冲坏。
    if (n <= 0)
        return -1;
    if (i < 1 || i > size)
        return -1;
    if (i + n - 1 > size) // 等价于原来的 rest < 0，但先判 i/n 合法更安全直观
        return -1;

    int begin_index = i - 1;         // 第i个位置对应下标 i-1（删除段起点）
    int after_del_index = i + n - 1; // 删除段之后第一个元素对应下标

    // ---- 错误写法2（已修正，保留对比）：循环变量与下标双重自增 ----
    // 原写法：
    //   for (int j = after_del_index; j < size; j++)
    //   {
    //       list[begin_index++] = list[after_del_index++];
    //   }
    // 说明：j 和 after_del_index 初值相同、每轮都 +1，碰巧结果是对的，
    //       但一个管循环次数、一个管搬移下标，读起来极易看错，
    //       一旦只改一处就会搬错/越界。更早版本还写成 for(int i=...) 遮蔽参数i，
    //       编译会报 -Wshadow 警告。
    // 正确写法：只用一个下标 k 做搬移，begin_index 顺序跟进：
    for (int k = after_del_index; k < size; k++)
    {
        list[begin_index++] = list[k];
    }
    size -= n;
    return 1;
}

// 原来 list_display() 只在类内声明、没有定义，main 一旦调用会链接失败，这里补上
void SeqList::list_display()
{
    std::cout << size << " ";
    for (int j = 0; j < size; j++)
    {
        std::cout << list[j] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    // 第1行：n + n个数据，建表后输出
    int n;
    if (!(std::cin >> n))
        return 0;
    int *init = new int[n > 0 ? n : 1];
    for (int j = 0; j < n; j++)
        std::cin >> init[j];

    SeqList L;
    L.multiinsert(1, n, init); // 空表从位置1插入n个，即建表
    delete[] init;
    L.list_display();

    // 第2行：i k + k个数据，连续插入后输出
    int pos_in, k_in;
    std::cin >> pos_in >> k_in;
    int *ins = new int[k_in > 0 ? k_in : 1];
    for (int j = 0; j < k_in; j++)
        std::cin >> ins[j];
    L.multiinsert(pos_in, k_in, ins);
    delete[] ins;
    L.list_display();

    // 第3行：i k，从i开始连续删除k个后输出
    int pos_del, k_del;
    std::cin >> pos_del >> k_del;
    L.multidel(pos_del, k_del);
    L.list_display();

    return 0;
}
#include <iostream>
#define ok 0
#define error -1

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
    {
        return error;
    }
    // [原错误写法缺失] 未判断 n<0 与满表 size+n>maxsize
    // [说明] n为负会乱搬移，满表会堆越界写
    if (n < 0 || size + n > maxsize)
        return error;
    if (n == 0)
        return ok;

    // [原错误写法保留] int flag = size - 1; int t = size - i - 1; while (t--) { list[flag+n]=list[flag]; flag--; }
    // [说明] 应搬 size-i+1 个，这里只搬 size-i-1 个，少搬 2 个，中部数据会被覆盖丢失。
    //        且尾插 i=size+1 时 t=-2，while(t--) 判非零为真，会死循环。
    //        应从 size-1 倒着搬到 i-1 为止。
    for (int t = size - 1; t >= i - 1; --t)
        list[t + n] = list[t];

    // [原54.cpp此处已改对] list[begin++] = item[item_begin++]; 保留
    // [说明] 更早版本写 list[begin] 未递增 begin，会反复写同一格，这里已修正，保持递增写法。
    for (int j = 0; j < n; ++j)
        list[i - 1 + j] = item[j];
    size += n;

    // [原错误写法保留] return 1;
    // [说明] 成功应返回 ok(0)，与 52 题宏一致，而不是 1
    return ok;
}

int SeqList::multidel(int i, int n)
{
    int begin_del = i - 1;
    (void)begin_del;
    // [原错误写法保留，已在54.cpp改对] 曾写 if (n + i < size)
    // [说明] 删到尾 i+n-1==size 时本应成功，却判失败。现条件已改对，保留正确写法：
    if (!(i >= 1 && n >= 0 && i + n - 1 <= size))
        return error;
    if (n == 0)
        return ok;

    // [原错误写法保留] int after_del = i + n - 1; int rest = ...; new int[rest]; ... multiinsert(i, rest, arr); size = size - n;
    // [说明1] after_del=i+n-1 换算已对（= (i-1)+n），rest=size-i-n+1 个数也对，这两行可留。
    // [说明2] 但后面“拷到临时数组→调multiinsert回填→size-n”是错的：
    //        multiinsert 本身会后移+size+=rest，再 size-n 得 S+rest-n，比正确 S-n 大 rest。
    //        且 new[] 未 delete[] 泄漏，绕大弯不如直接前移。
    //        正确：把尾巴 [i-1+n, size) 直接前移 n 格。
    int tail_start = (i - 1) + n;
    for (int t = tail_start; t < size; ++t)
        list[t - n] = list[t];
    size -= n;

    // [原错误写法保留] return 1; [说明] 同上，成功应返回 ok
    return ok;
}

// [原54.cpp缺失] list_display 只声明未定义，这里补上，与52题一致
void SeqList::list_display()
{
    std::cout << size << " ";
    for (int i = 0; i < size; ++i)
        std::cout << list[i] << " ";
    std::cout << '\n';
}

int main()
{
    int n;
    if (!(std::cin >> n))
        return 0;
    SeqList s1;
    if (n > 0)
    {
        int *a = new int[n];
        for (int k = 0; k < n; ++k)
            std::cin >> a[k];
        s1.multiinsert(1, n, a);
        delete[] a;
    }
    s1.list_display();

    int pos, k;
    std::cin >> pos >> k;
    {
        int *b = new int[k > 0 ? k : 1];
        for (int j = 0; j < k; ++j)
            std::cin >> b[j];
        if (s1.multiinsert(pos, k, b) == -1)
            std::cout << "error" << '\n';
        else
            s1.list_display();
        delete[] b;
    }

    int dpos, dk;
    std::cin >> dpos >> dk;
    if (s1.multidel(dpos, dk) == -1)
        std::cout << "error" << '\n';
    else
        s1.list_display();

    return 0;
}

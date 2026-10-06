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
    int list_size();
    int list_insert(int i, int item);
    int list_del(int i);
    int list_get(int i);
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

int SeqList::list_size()
{
    return size;
}

int SeqList::list_insert(int i, int item)
{
    if (i < 1 || i > size + 1)
        return error;
    if (size >= maxsize)
        return error;

    int t = size - 1;
    while (t >= i - 1)
    {
        list[t + 1] = list[t];
        t--;
    }
    list[i - 1] = item;
    size++;
    return ok;
}

int SeqList::list_del(int i)
{
    if (i < 1 || i > size)
        return error;
    int t = i - 1;
    while (t < size - 1)
    {
        list[t] = list[t + 1];
        t++;
    }
    size--;
    return ok;
}

int SeqList::list_get(int i)
{
    if (i < 1 || i > size)
        return error;

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
    int flag6 = s1.list_get(find2);

    if (flag6 == -1)
        std::cout << "error" << '\n';
    else
        std::cout << flag6 << '\n';

    return 0;
}

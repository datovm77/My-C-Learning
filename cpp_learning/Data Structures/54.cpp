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
    {
        return -1;
    }

    int flag = size - 1;
    int t = size - i - 1;
    while (t--)
    {
        list[flag + n] = list[flag];
        flag--;
    }
    int temp_n = n;
    int begin = i - 1;
    int item_begin = 0;
    while (temp_n--)
    {
        list[begin++] = item[item_begin++];
        size++;
    }

    return 1;
}

int SeqList::multidel(int i, int n)
{
    int begin_del = i - 1;
    if (i >= 1 && n >= 0 && i + n - 1 <= size)
    {
        int after_del = i + n - 1;
        int rest = size - i - n + 1;
        int *arr = new int[rest];
        int temp = 0;
        while (rest--)
        {
            arr[temp] = list[after_del];
            temp++;
            after_del++;
        }
        multiinsert(i, rest, arr);
        size = size - n;
    }
    else
    {
        return -1;
    }
    return 1;
}

int main()
{

    return 0;
}
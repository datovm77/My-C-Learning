#include <iostream>
using namespace std;

class SeqList
{
private:
    int data[1000];
    int length;

public:
    SeqList(int n)
    {
        length = n;
        for (int i = 0; i < n; i++)
        {
            cin >> data[i];
        }
    }

    void move(int direction, int k)
    {
        k %= length;

        int temp[1000];

        if (direction == 0)
        { // 左移
            for (int i = 0; i < length; i++)
            {
                temp[i] = data[(i + k) % length];
            }
        }
        else
        { // 右移
            for (int i = 0; i < length; i++)
            {
                temp[i] = data[(i - k + length) % length];
            }
        }

        for (int i = 0; i < length; i++)
        {
            data[i] = temp[i];
        }
    }

    void print()
    {
        for (int i = 0; i < length; i++)
        {
            cout << data[i] << " ";
        }
        cout << endl;
    }
};

int main()
{
    int n;
    cin >> n;

    SeqList list(n);

    // 创建后的顺序表
    list.print();

    int direction, k;

    // 第一次移位
    cin >> direction >> k;
    list.move(direction, k);
    list.print();

    // 第二次移位
    cin >> direction >> k;
    list.move(direction, k);
    list.print();

    return 0;
}
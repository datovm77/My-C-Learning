// 练习函数模板实现冒泡排序与打印
#include <iostream>
#include <cstring>

template <typename T>
void my_sort(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                T temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void test01()
{
    char arr[] = "geteverbody";
    int len = strlen(arr);
    my_sort(arr, len);
}

template <typename T>
void print(T arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        std::cout << arr[i];
    }
    std::cout << std::endl;
}

int main()
{
    test01();

    return 0;
}
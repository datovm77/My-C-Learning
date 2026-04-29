// 练习二维数组三种内存分配方式，栈区、混合与堆区
#include<iostream>
using namespace std;

int main()
{
    // ===== 方式一：全部在栈区 =====
    cout << "===== 方式一：全部在栈区 =====" << endl;
    int arr[3][4];

    // 初始化数据
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            arr[i][j] = i * 4 + j + 1;
        }
    }

    // 输出数据
    cout << "栈区二维数组数据：" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    // ===== 方式二：行在栈区，列在堆区 =====
    cout << "===== 方式二：行在栈区，列在堆区 =====" << endl;
    int *arr2[3];  // 栈区存放3个指针

    // 为每一行分配堆区内存
    for (int i = 0; i < 3; i++) {
        arr2[i] = new int[4];
    }

    // 初始化数据
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            arr2[i][j] = i * 4 + j + 1;
        }
    }

    // 输出数据
    cout << "栈堆混合二维数组数据：" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << arr2[i][j] << "\t";
        }
        cout << endl;
    }

    // 释放内存
    for (int i = 0; i < 3; i++) {
        delete[] arr2[i];
    }
    cout << endl;

    // ===== 方式三：全部在堆区 =====
    cout << "===== 方式三：全部在堆区 =====" << endl;
    int **arr3 = new int* [3];  // 堆区存放指针数组

    // 为每一行分配堆区内存
    for (int i = 0; i < 3; i++) {
        arr3[i] = new int[4];
    }

    // 初始化数据
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            arr3[i][j] = i * 4 + j + 1;
        }
    }

    // 输出数据
    cout << "堆区二维数组数据：" << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            cout << arr3[i][j] << "\t";
        }
        cout << endl;
    }

    // 释放内存（先释放行，再释放指针数组）
    for (int i = 0; i < 3; i++) {
        delete[] arr3[i];
    }
    delete[] arr3;
    cout << endl;

    return 0;
}

#include <stdio.h>

void printArr(char arr[], int len);

int main()
{
    char arr[7] = {0};  // 固定7个字符
    int len = sizeof(arr) / sizeof(arr[0]);  // len = 7

    printf("请输入: ");
    
    // 一次性录入（逐个用 getchar 从缓冲区读）
    for (int i = 0; i < len; i++)
    {
        char ch = getchar();
        
        arr[i] = ch;
    }

    // 遍历数组
    printf("原始字符数组: ");
    printArr(arr, len);

    // 反转数组
    int i = 0, j = len - 1;
    while (i < j)
    {
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }

    // 输出反转结果
    printf("反转后的字符数组: ");
    printArr(arr, len);

    return 0;
}

void printArr(char arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%c", arr[i]);
    }
    printf("\n");
}

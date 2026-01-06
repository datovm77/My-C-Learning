#include<stdio.h>

//字符串反转

void printArr(char arr[], int len);

int main()
{
    char arr[7] = {0};
    int len = sizeof(arr) / sizeof(arr[0]);
    
    printf("请一次性输入%d个字符（不要空格，直接连续输入）: ", len);
    
    // 一次性读取所有字符
    for(int i = 0; i < len; i++)
    {
        scanf("%c", &arr[i]);
    }
    
    
    // 遍历数组
    printf("原始字符数组: ");
    printArr(arr, len);
    
    // 反转数组
    int i = 0;
    int j = len - 1;
    while(i < j)
    {
        char temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }
    
    // 遍历数组
    printf("反转后的字符数组: ");
    printArr(arr, len);
    
    return 0;
}

void printArr(char arr[], int len)
{
    for(int i = 0; i < len; i++)
    {
        printf("%c", arr[i]);
    }
    printf("\n");
}
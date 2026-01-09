#include <stdio.h>
#include <string.h> // 必须包含：用于 strcmp 和 strcpy

int main()
{
    // 1. 定义数据结构
    // 二维数组：存放5个字符串，每个字符串最多容纳79个字符（留一个给\0）
    char str[5][80]; 
    char temp[80];   // 临时仓库：用于交换时的暂存，大小必须和字符串一样

    // 2. 输入数据
    // scanf("%s") 会自动跳过空格读取下一个单词，非常适合处理一行输入多个字符串的情况
    for(int i = 0; i < 5; i++)
    {
        scanf("%s", str[i]);
    }

    // 3. 冒泡排序核心代码 (重点背诵区域)
    int n = 5; // 待排序元素的个数
    
    // 外层循环：控制“轮数”。5个数只需排4轮（n-1）
    for(int i = 0; i < n - 1; i++) 
    {
        // 内层循环：控制每一轮的“比较次数”
        // 每一轮结束后，最大的那个“气泡”就已经冒到了最后，所以下一轮可以少比一次 (n-1-i)
        for(int j = 0; j < n - 1 - i; j++) 
        {
            // 核心比较：如果 前者 > 后者 (字典序)
            if(strcmp(str[j], str[j+1]) > 0) 
            {
                // 核心交换：三步走 (使用strcpy)
                strcpy(temp, str[j]);       // 1. 把前者放入临时仓库
                strcpy(str[j], str[j+1]);   // 2. 把后者赋值给前者
                strcpy(str[j+1], temp);     // 3. 把仓库里的值给后者
            }
        }
    }

    // 4. 格式化输出
    printf("After sorted:\n");
    for(int i = 0; i < 5; i++)
    {
        printf("%s\n", str[i]);
    }

    return 0;
}
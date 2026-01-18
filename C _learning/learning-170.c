#include<stdio.h>
#include<string.h>

#define OFFSET 10000
#define MAX_SIZE 20005

int arr_map[MAX_SIZE]; // 全局数组，防止爆栈

int main()
{
    int n, m;
    while(scanf("%d %d", &n, &m) != EOF)
    {
        if(n == 0 && m == 0) break;
        
        // 1. 初始化清零
        memset(arr_map, 0, sizeof(arr_map));

        // 2. 读入集合 A
        for(int i = 0; i < n; i++)
        {
            int val;
            scanf("%d", &val);
            if(val + OFFSET >= 0 && val + OFFSET < MAX_SIZE)
            {
                arr_map[val + OFFSET] = 1;
            }
        }

        // 3. 读入集合 B (执行减法)
        for(int i = 0; i < m; i++)
        {
            int val;
            scanf("%d", &val);
            if(val + OFFSET >= 0 && val + OFFSET < MAX_SIZE)
            {
                arr_map[val + OFFSET] = 0; // 只要B里有，就抹掉A里的标记
            }
        }

        // 4. 输出结果
        int found = 0;
        for(int i = 0; i < MAX_SIZE; i++)
        {
            if(arr_map[i] == 1)
            {
                int real_val = i - OFFSET; // 还原真实数值
                
                // 【格式控制核心】
                if(!found) {
                    printf("%d", real_val); // 第一个数，前面没空格
                    found = 1;              // 标记找到至少一个了
                } else {
                    printf(" %d", real_val); // 后面的数，前面加空格
                }
            }
        }

        // 5. 收尾工作
        if(!found)
        {
            printf("NULL\n");
        }
        else
        {
            printf("\n"); // 【重要】如果有输出数字，最后必须换行！
        }
    }

    return 0;
}
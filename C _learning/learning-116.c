#include <stdio.h>

// 根据题目范围设定 MAX。
// 如果题目没说范围，一般练习题 100000 够用了。
// 如果是很大的范围（比如1000万），这个数组要开在 main 函数外面（全局变量）
#define MAX 100005 

int sum[MAX] = {0}; // 用来存储每个数字的因子和

int main()
{
    int start, end;
    if (scanf("%d %d", &start, &end) != 2) return 1;

    // --- 核心预处理开始 (筛法) ---
    // 既然要求区间 [start, end] 的亲密数，我们需要知道 end 以内所有数的因子和。
    // 甚至可能需要稍微多算一点点（因为 friend 可能比 end 大），但在题目限制下，
    // 我们通常先算出 max(end) 范围内的表。
    
    // 1. 遍历所有可能的因子 i (从 1 开始，一直试到 end/2)
    // 为什么只到 end/2？因为超过一半的数不可能是真因子了
    for (int i = 1; i <= end / 2; i++)
    {
        // 2. 把 i 加给它的所有倍数 j
        // j 从 i*2 开始，因为真因子不包含数字本身
        for (int j = i * 2; j <= end; j += i)  //这个*2的目的是为了避开自身被放入因子
        {
            sum[j] += i;
        }
    }
    // --- 预处理结束 ---

    int found = 0;

    // 直接查表输出，速度飞快
    for (int a = start; a <= end; a++)
    {
        // 直接从数组里拿 a 的因子和
        int b = sum[a];

        // 这里的逻辑和之前一样
        if (a < b && b <= end) 
        {
            // 直接查表看 b 的因子和是不是 a
            if (sum[b] == a)
            {
                printf("(%d,%d)", a, b);
                found = 1;
            }
        }
    }

    if (!found)
    {
        printf("-1");
    }

    return 0;
}
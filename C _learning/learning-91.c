#include <stdio.h>

int main()
{
    int n, x;
    int count = 0; // 用于统计 x 出现的总次数

    // 1. 输入 n 和 x
    scanf("%d %d", &n, &x);

    // 2. 遍历从 1 到 n 的每一个数字
    for(int i = 1; i <= n; i++)
    {
        int temp = i; 
        
        while(temp != 0)
        {
            int wei = temp % 10;
            
            if(wei == x)
            {
                count++;
            }
            
            temp = temp / 10; 
        }
    }

    // 4. 输出总次数
    printf("%d\n", count);

    return 0;
}
#include <stdio.h>

int main() 
{
    for(int a = 123; a <= 329; a++)
    {
        int b = 2 * a;
        int c = 3 * a;
        
        int arr[10] = {0}; // 桶初始化
        int nums[3] = {a, b, c}; // 打包
        

        // 外层循环：依次处理 a, b, c
        for(int i = 0; i < 3; i++) {
            int x = nums[i]; // 取出当前的数
            
            // 内层循环：剥洋葱，拆每一位
            while(x > 0) 
            {
                int digit = x % 10; // 取最后一位
                arr[digit] = 1;     // 标记,如果下表不重合，则0-9下表的值对应的数组都应该变为1
                x = x / 10;         // 去掉最后一位
            }
        }
        // ==== 核心优化部分 结束 ====
        
        // 最后的检查逻辑不变
        int count = 0;
        for(int j = 1; j <= 9; j++)
        {
            count += arr[j];
        }
        
        // 记得检查 arr[0] 必须是 0，防止出现数字 0
        if(count == 9 && arr[0] == 0)
        {
            printf("%d %d %d\n", a, b, c);
        }
    } 
    return 0;
}
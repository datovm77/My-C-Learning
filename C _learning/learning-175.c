#include<stdio.h>

int main()
{
    int n; // 测试用例数
    if(scanf("%d",&n) == EOF) return 0;
    while (n--)
    {
        int len;
        scanf("%d",&len);
        
        // 1. 计算幻方常数 (Target Sum)
        int result = len*(1+len*len)/2;
        
        // 使用变长数组(VLA)，C99标准支持
        int arr[len][len];
        
        // 2. 输入矩阵
        for(int i = 0;i<len;i++)
        {
            for(int j = 0;j<len;j++)
            {
                scanf("%d",&arr[i][j]);
            }
        }

        int found = 1;

        // 3. 检查 行 和 列
        for(int i = 0;i<len;i++)
        {
            int sum_hang = 0;
            int sum_lie = 0;
            for(int j = 0;j<len;j++)
            {
                sum_hang += arr[i][j]; // 第i行
                sum_lie += arr[j][i];  // 第i列 (注意这里j变i不变)
            }
            if(sum_hang != result || sum_lie != result)
            {
                found = 0;
                break;
            }
        }

        // 4. 检查 两条对角线 (重点修改区域)
        if(found) 
        {
            int sum_main = 0; // 主对角线
            int sum_anti = 0; // 副对角线
            
            for(int i = 0;i<len;i++)
            {
                sum_main += arr[i][i];           // 左上 -> 右下
                sum_anti += arr[i][len - 1 - i]; // 右上 -> 左下
            }
            
            if(sum_main != result || sum_anti != result)
            {
                found = 0;
            }
        }

        if(found) printf("YES\n");
        else printf("NO\n");
    }
    
    return 0;
}
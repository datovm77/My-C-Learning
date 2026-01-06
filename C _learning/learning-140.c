#include<stdio.h>
#include<string.h>

//数组标记法
#define OFFSET 2000
#define MAX_VAL 4005

int main()
{
    int arr1[25] ;
    int arr2[25] ;
    int num1,num2;

    // 标记数组 (初始化为0)
    // in_arr1: 用来快速查某个数是不是在 arr1 里
    // in_arr2: 用来快速查某个数是不是在 arr2 里
    // printed: 用来记录某个数是不是已经输出过了（去重用）
    int in_arr1[MAX_VAL] = {0};
    int in_arr2[MAX_VAL] = {0};
    int printed[MAX_VAL] = {0};

    int first_print = 1; // 控制空格输出的“开关”

    //输入arr1并且建立索引
    if(scanf("%d",&num1)==1)
    {
        for(int i = 0;i<num1;i++)
        {
            scanf("%d",&arr1[i]);
            in_arr1[arr1[i]+OFFSET] = 1;  //本来是0变成1
        }
    }

    // 3. 输入 arr2 并建立索引
    // 这里 num2 可以和 num1 不一样，完全独立
    if (scanf("%d", &num2) == 1) { 
        for (int i = 0; i < num2; i++) {
            scanf("%d", &arr2[i]);
            // 核心步骤：在 in_arr2 对应的位置打钩
            in_arr2[arr2[i] + OFFSET] = 1;
        }
    }
    //第一轮遍历，找到arr1中独有的
    for(int i = 0;i<num1;i++)
    {
        int val = arr1[i];
        int idx = val + OFFSET;
        // 判断条件：
        // (1) in_arr2[idx] == 0  -> 说明 arr2 里没有这个数
        // (2) printed[idx] == 0  -> 说明之前没打印过 (防止 arr1 自己有重复)
        if(in_arr2[idx]==0&&printed[idx]==0)
        {
            if(first_print==0)
            {
                printf(" ");
            }
            printf("%d",val);
            first_print = 0;
            printed[idx] = 1;
        }
    }
    for (int i = 0; i < num2; i++) {
        int val = arr2[i];
        int idx = val + OFFSET;

        // 判断条件：
        // (1) in_arr1[idx] == 0  -> 说明 arr1 里没有这个数
        // (2) printed[idx] == 0  -> 说明之前没打印过
        if (in_arr1[idx] == 0 && printed[idx] == 0) {
            
            if (first_print == 0) {
                printf(" ");
            }
            printf("%d", val);
            
            first_print = 0;
            printed[idx] = 1;
        }
    }
    printf("\n");

    return 0;

}
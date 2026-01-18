#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    
    for(int i = 0;i<n;i++)
    {
        int arr[10];
        for(int j = 0;j<6;j++)
        {
            scanf("%d",&arr[j]);
        }
        
        // 必须初始化为0，因为我们要用 +=
        int arrr[5] = {0}; 
        
        for(int k = 2; k >= 0; k--)
        {
            // 【核心修改】把 = 改成 +=
            // 这样如果低位刚才进位了(arrr[k]已经是1了)，这里会累加，而不是覆盖
            arrr[k] += arr[k] + arr[k+3]; 
            
            if(arrr[k] >= 60 && k > 0)
            {
                arrr[k] -= 60;
                arrr[k-1]++; // 进位给高位
            }
        }

        for(int p = 0;p<3;p++)
        {
            printf("%d ",arrr[p]);
        }
        printf("\n");
    }

    return 0;
}
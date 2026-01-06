#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//方法二，一个个处理
int main(void)
{

    int m,n;//m是行，n是列
    while(scanf("%d %d",&m,&n) == 2)
    {
        if(m==0||n==0)
        {
            return 0;
        }
        int currentVal;//存放刚刚读取的数
        //初始化
        int maxVal = 0;  //记录当前绝对值最大的值
        int maxRow = 1;  //行
        int maxCol = 1;  //列

        for(int i = 0;i<m;i++)//行循环
        {
            for(int k = 0;k<n;k++)//列循环
            {
                scanf("%d",&currentVal);

                //直接让第一个数作为最大值
                if(i==0 && k==0)
                {
                    maxVal = currentVal;
                    maxCol = 1;
                    maxRow = 1;
                }
                else if(abs(currentVal)>abs(maxVal))
                {
                    maxVal = currentVal;
                    maxCol = k + 1;  //更新列
                    maxRow = i + 1;  //更新行
                }
            }
        }

        printf("%d %d %d\n",maxRow,maxCol,maxVal);


    }


    return 0;
}
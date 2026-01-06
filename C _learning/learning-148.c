#include<stdio.h>
//二维数组的处理
int main(void)
{
    int n,m;//n代表学生数列，m表示课程数量
    while(scanf("%d %d",&n,&m)==2)
    {
        if(n==0||m==0)
        {
            return 0;
        }
        int arr[n][m];//存放学生的成绩
        double stu_aver[n];//学生平均分
        double sub_aver[m];//学科平均分
        
        
        for(int i = 0;i<n;i++)
        {
            for(int j = 0;j<m;j++)
            {
                scanf("%d",&arr[i][j]);
            }
        }
        
        for(int i = 0;i<n;i++)
        {
            double stu_sum = 0; //学生总分
            
            for(int j = 0;j<m;j++)
            {
                stu_sum += arr[i][j];
                
            }
            stu_aver[i] = stu_sum*1.0 / m;
        }
        //printf("%.2lf",stu_aver[0]);

        for(int j = 0;j<m;j++)
        {
            double sub_sum = 0;
            for(int i = 0;i<n;i++)
            {
                sub_sum += arr[i][j];
            }
            sub_aver[j] = sub_sum/n;
        }
        int count = 0;
        for(int i = 0;i<n;i++)
        {
            int pass = 1;
            for(int j = 0;j<m;j++)
            {
                if(arr[i][j]<sub_aver[j])
                {
                    pass = 0;
                    break;
                }
            }
            if(pass) count++;
        }

        // 5. 输出结果 (根据题目要求调整格式)
        // 输出学生平均分
        for(int i = 0; i < n; i++) {
            printf("%.2lf%c", stu_aver[i], (i == n-1) ? '\n' : ' ');
        }
        
        // 输出学科平均分
        for(int j = 0; j < m; j++) {
            printf("%.2lf%c", sub_aver[j], (j == m-1) ? '\n' : ' ');
        }

        // 输出计数
        printf("%d\n\n", count);
    

    }


    return 0;
}
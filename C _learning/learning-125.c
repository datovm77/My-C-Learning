#include<stdio.h>
int main()
{
    int T;
    while(scanf("%d",&T) != EOF)
    {
        
        
        int sum = 0;
        int max = -1;
        int min = 101;
        for(int i = 0;i<T;i++)
        {
            int number;
            scanf("%d",&number);
            if(number > max)
            {
                max = number;
            }
            if(number < min)
            {
                min = number;
            }
            sum += number;
        }
        double real_sum = 1.0*(sum - max - min) / (T-2);
        printf("%.2lf\n",real_sum);


    }




    return 0;
}
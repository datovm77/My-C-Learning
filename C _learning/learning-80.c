#include<stdio.h>
int main()
{
    int num;
    scanf("%d",&num);
    if(num<=150)
    {
        double cost = 0.4463 * num;  

        printf("%.1lf \n",cost);
    }
    else if(num>=151 && num <= 400)
    {
        double cost = 0.4463*150.0 + (num-150)*0.4663;
        printf("%.1lf \n",cost);
    }
    else{
        double cost = 0.4463*150.0 + 250*0.4663 + (num-400) * 0.5663;
        printf("%.1lf \n",cost);
    }


    return 0;
}
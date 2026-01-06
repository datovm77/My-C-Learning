#include<stdio.h>
int main(void)
{
    int ceil_up(double n);
    int area;
    double weight;
    scanf("%d,%lf",&area,&weight);
    int real_weight = ceil_up(weight);

    double price;
    switch (area)
    {
    case 0:
        if(real_weight == 1)
        {
           printf("Price: 10.00\n"); 
        }
        else if(real_weight > 1)
        {
            price = 10.00 + (real_weight - 1)*3.0;
            printf("Price: %.2lf\n",price); 
        }
        break;
    case 1:
        if(real_weight == 1)
        {
           printf("Price: 10.00\n"); 
        }
        else if(real_weight > 1)
        {
            price = 10.00 + (real_weight - 1)*4.0;
            printf("Price: %.2lf\n",price); 
        }
        break;
    case 2:
        if(real_weight == 1)
        {
           printf("Price: 15.00\n"); 
        }
        else if(real_weight > 1)
        {
            price = 15.00 + (real_weight - 1)*5.0;
            printf("Price: %.2lf\n",price); 
        }
        
        break;
    case 3:
        if(real_weight == 1)
        {
           printf("Price: 15.00\n"); 
        }
        else if(real_weight > 1)
        {
            price = 15.00 + (real_weight - 1)*6.5;
            printf("Price: %.2lf\n",price); 
        }
        
        break;
    case 4:
        if(real_weight == 1)
        {
           printf("Price: 15.00\n"); 
        }
        else if(real_weight > 1)
        {
            price = 15.00 + (real_weight - 1)*10.0;
            printf("Price: %.2lf\n",price); 
        }
        break;
    
    default:
        printf("Error in Area\n");
        printf("Price: 0.00\n");
        break;
    }

    return 0;
    
}

int ceil_up(double n) //向上取整函数!!重点！！！
{
    int i = (int)n;   // 直接截断小数部分
    if (n > i)        // 如果有小数部分
        return i + 1;
    else
        return i;
}

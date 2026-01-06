#include <stdio.h>
int num_add(int n);
int main()
{
    int num;
    scanf("%d",&num);
    int temp = num;
    while(num_add(temp) >= 10)
    {
        temp = num_add(temp);
    }
    printf("%d\n",num_add(temp));
    

    return 0;
}

int num_add(int n)
{
    int sum = 0;
    int temp = n;
    while(temp != 0)
    {
        int num = temp % 10;
        sum = sum + num;
        temp = temp / 10;
    }
    return sum;
}
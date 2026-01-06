//共同体
#include<stdio.h>

union MoneyType
{
    int moneyi;
    double moneyd;
    char moneystr[100];
};

int main()
{
    //利用共同体
    union MoneyType money;
    //可以赋值整数(moneyi)，小数(moneyd)，字符串(moneystr)
    //每次只可以赋一次值 
    printf("%zu \n",sizeof(money.moneyi));
    printf("%zu \n",sizeof(money.moneyd));
    printf("%zu \n",sizeof(money.moneystr));

    printf("------------------------------------\n");

    printf("%p \n",(money.moneyi));
    printf("%p \n",(money.moneyd));
    printf("%p \n",(money.moneystr));
    printf("------------------------------------\n");
    printf("%p \n",&(money.moneyi));
    printf("%p \n",&(money.moneyd));
    printf("%p \n",&(money.moneystr));

    return 0 ;
}
#include<stdio.h>
int main()
{
    //输入一个三位数，然后分别打印百位，十位，个位
    int num;
    printf("请输入一个三位数： \n");
    scanf("%d",&num);
    
    //拆分
    int ge = num % 10;   //一个三位数除以10的余数为个位
    int shi = num / 10 % 10 ;
    int bai = num / 100 % 10;
    printf("百位：%d \n",bai);
    printf("十位：%d \n",shi);
    printf("个位：%d \n",ge);
  
    return 0;
}

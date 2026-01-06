#include<stdio.h>
int digit_sum(int a){	//计算一个数各位数相加的和 
    int sum = 0;
	while(a){ 
		sum	+=	a % 10;	//sum是个位数之和
		a /= 10;
	}
   return sum;
}

int main(){
/*********begin*********/
    int num,n;
    scanf("%d",&n);
    for(int i = 0;i<n;i++)
    {
        scanf("%d",&num);
        int flag = 0;
        int sum = digit_sum(num);
        for(int j = 1;j<=9;j++)
        {
            int new_num = num*j;
            if(digit_sum(new_num) != sum)
            {
                printf("NO\n");
                flag = 1;
                break;
            }
        }
        if(flag==0)
        {
            printf("%d\n",sum);
        }
    }
    





/**********end**********/
   return 0;
}
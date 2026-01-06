#include<stdio.h>
int main()
{
	short a = 10;    //完整为： short int a = 10；
	int b = 100;     
	long c = 1000L;  //完整为：long int c = 1000L;
	long long d = 10000LL; //完整为：long long int d = 10000LL;
    //测量short，int,long,long long类型变量的存储空间

	printf("%zu \n", sizeof(short)); //zu表示sizeof的测量结果
	printf("%zu \n",sizeof(a)); //sizeof中间既可以填数据类型，也可以填变量名,运行结果为 2

	printf("%zu \n", sizeof(int));
	printf("%zu \n", sizeof(b)); //运行结果为4

	printf("%zu \n", sizeof(long));
	printf("%zu \n", sizeof(c)); //运行结果为4

	printf("%zu \n", sizeof(long long));
	printf("%zu \n", sizeof(d)); //运行结果为8

	return 0;
}
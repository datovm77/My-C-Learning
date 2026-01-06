#include<stdio.h>
#include<math.h>
int main()
{
   //=======begin=======
   int a,b,c;
   scanf("%d %d %d",&a,&b,&c);
   double s = (a+b+c) / 2.0;
   double area = sqrt(s*(s-a)*(s-b)*(s-c));
    double zhouchang = a+b+c;
    printf("area = %.2lf perimeter = %.2lf;",area,zhouchang);
   //========end========
   return 0;
}
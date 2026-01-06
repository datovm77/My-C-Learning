#include<stdio.h>
#include<stdlib.h>
int main()
{
    /*
    fgetc 一次读一行，读不到返回-1
    fgets 一次读一行
    fread 一次读多行
    */
   FILE *p1 =fopen ("D:\\show.txt","r");
   int n;
   char arr[4];

   while((n = fread(arr,1,4,p1)) != 0)
   {
        for(int i = 0;i < n;i++)
        {
            printf("%c",arr[i]);
        }
    }


    return 0;
}
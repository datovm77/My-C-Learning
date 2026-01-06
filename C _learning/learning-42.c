#include<stdio.h>
int main()
{
    int arr[5] = {1,2,3,4,5};
    int* p = arr;
    int* p2 = &arr[0];
    int* p1 = arr + 1;
    printf("%p \n",p);  //00000000005FFE40 
    printf("%p \n",p1); //00000000005FFE44 
    printf("%p \n",p2); //00000000005FFE40 
    printf("%d \n",*(p+1));

    int len = sizeof(arr) / sizeof(int);
    for(int i = 0;i < len;i++)
    {
        printf("%d",*(p+i));
        //p++;
    }


    return 0;
}
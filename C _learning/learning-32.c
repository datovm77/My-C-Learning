#include<stdio.h>

void swap(void* p1,void* p2,int len);
int main()
{
    short c = 500;
    short d = 100;

    swap(&c,&d,2); 

    printf("c = %d, d = %d\n",c,d);

    return 0;
}

void swap(void* p1,void* p2,int len)
{
    char* pc1 = p1;
    char* pc2 = p2;

    char temp = 0;

    for(int i = 0; i < len; i++)
    {
        temp = *pc1;
        *pc1 = *pc2;
        *pc2 = temp;

        pc1++;
        pc2++;
 
    }
    
}
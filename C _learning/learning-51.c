#include<stdio.h>
int main()
{
    int zippo[4][2] = 
    {
        {2,4},
        {4,5},
        {8,5},
        {9,7}
    };

    int (*p)[2];
    p = zippo;
    printf("%p \n",p);  //00000000005FFE50 
    printf("%p \n",p+1);//00000000005FFE58 
    printf("%p \n",p[0]);//00000000005FFE50
    printf("%p \n",p[0]+1);//00000000005FFE54 
    printf("%p \n",*p);  //00000000005FFE50
    printf("%p \n",*p+1);//00000000005FFE54

    return 0;
}
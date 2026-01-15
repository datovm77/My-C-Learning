#include<stdio.h>
#include<string.h>
int main()
{
    char number[10000];
    int num_single;
    scanf("%s %d",number,&num_single);
    int count = 0;
    int len = strlen(number);
    for(int i = 0;i<len;i++)
    {
        if(number[i]== num_single + '0')
        {
            count++;
        }
    }
    printf("Number of digit %d in %s: %d",num_single,number,count);

    return 0;
}
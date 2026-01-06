#include<stdio.h>
int main()
{
    int count,word;
    char ch;
    word= count =0;
    printf("输入字母： \n");
    while((ch=getchar())!='\n')
    {
        if(ch==' ')
        {
            word = 0;
        }
        else if(word == 0)
        {
            word = 1;
            count++;
        }
        
    
    }
    printf("%d \n",count);

    return 0;
}
#include<stdio.h>
#include<ctype.h>
#include<string.h>
// int isVowel(char ch)
// {
//     if((ch=='a')||(ch=='e')||(ch=='i')||(ch=='o')||(ch=='u'))
//     {
//         return 1;
//     }
//     else{
//         return 0;
//     }
// }
int main()
{
    int n;
    scanf("%d",&n);
    while(getchar()!='\n');
    for(int j = 0;j<n;j++)
    {
        char str[110];
        int Vowel[5] = {0};
        fgets(str,sizeof(str),stdin);
        int len = strlen(str);
        if(len>0 && str[len-1]=='\n')
        {
            str[len-1] = '\0';
            len--;
        }
        for(int i = 0;i<len;i++)
        {
            if(str[i]=='a')
            {
                Vowel[0]++;
            }
            if(str[i]=='e')
            {
                Vowel[1]++;
            }
            if(str[i]=='i')
            {
                Vowel[2]++;
            }
            if(str[i]=='o')
            {
                Vowel[3]++;
            }
            if(str[i]=='u')
            {
                Vowel[4 ]++;
            }
        }
        if(j>0) printf(" \n");
        printf("a:%d\n",Vowel[0]);
        printf("e:%d\n",Vowel[1]);
        printf("i:%d\n",Vowel[2]);
        printf("o:%d\n",Vowel[3]);
        printf("u:%d\n",Vowel[4]);
    
    }



    return 0;
}


#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char str[110];
    while(fgets(str,sizeof(str),stdin)!=NULL)
    {
        int len = strlen(str);
        for(int i = 0;i<len;i++)
        {
            if(i==0 || str[i-1]==' ')
            {
                str[i] = toupper(str[i]);
            }
        }


        printf("%s",str);
    }




}
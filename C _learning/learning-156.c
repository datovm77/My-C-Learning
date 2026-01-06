#include<stdio.h>
#include<string.h>

int main()
{
    
    char str[650] = {0}; 
    
    while((fgets(str,sizeof(str),stdin))!=NULL)
    {
        int len = strlen(str);
        if(len > 0 && str[len-1] == '\n')
        {
            str[len-1] = '\0';
            len--;
        }

        
        char max = str[0];
        
        for(int i = 0; i < len; i++)
        {
            if(str[i] > max) 
            {
                max = str[i];
            }
        }

        char target = max; 

        for(int i = 0; i < len; i++)
        {
            if(str[i] == target)
            {
                
                for(int j = len; j > i; j--) 
                {
                    str[j+5] = str[j];
                }
                
                // 插入字符
                str[i+1] = '(';
                str[i+2] = 'm';
                str[i+3] = 'a';
                str[i+4] = 'x';
                str[i+5] = ')';
                
                len += 5; 
                i += 5;   
            }
        }
        printf("%s\n", str);
        
    }

    return 0;
}
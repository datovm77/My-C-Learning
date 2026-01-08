#include<stdio.h>
#include<string.h>

int main()
{
    int n;
    scanf("%d",&n);
    getchar();
    while(n--)  //非0都是代表真，0代表假
    {
        char str[1000];

        if(fgets(str,sizeof(str),stdin)!=NULL)
        {
            int count = 0;
            for(int i = 0;str[i]!='\0';i++)
            {
                if(str[i]<0)
                {
                    count++;
                }
            }
            printf("%d\n",count/2);
        }
        
    }
    return 0;

}
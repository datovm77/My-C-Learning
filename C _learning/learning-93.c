#include<stdio.h>
int main()
{
    int num_rem[500];
    int temp;
    scanf("%d",&temp);
    int i = 0;
    while(1)
    {
        num_rem[i] = temp;
        scanf("%d",&temp);
        if(temp == 0)
        {
            break;
        }
        i++;
    }
    // for(int j = 0; j < i;j++)
    // {
    //     printf("%c",num_rem[j]);
    // }
    for(int j = i;j>=0;j--)
    {
        printf("%d ",num_rem[j]);

    }



    return 0;
}
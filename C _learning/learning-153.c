#include<stdio.h>
int main()
{
    int arr[15] = {0};
    char c;
    getchar();
    while((c=getchar()) && c !=EOF)
    {
        if(c>='0'&& c<='9')
        {
            int a = c-'0';
            // printf("%d",a);
            arr[a]++;
        }
    }
    int max = arr[0];
    int arr_index[10];
    int index = 0;
    for(int i = 1;i<15;i++)
    {
        if(arr[i]>=max)
        {
            max = arr[i];
        }
    }
    for(int i = 0;i<15;i++)
    {
        if(arr[i]==max)
        {
            arr_index[index] = i;
            index++;

        }
    }
    printf("%d: ",max);
    for(int i = 0;i<index;i++)
    {
        if(i>0) printf(" ");
        printf("%d",arr_index[i]);
        
    }
    printf("\n");
    return 0;
}